#include "base/nebu_types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

//R.K. some weird offset needed for the dir
//#ifdef WINS
#define FILE_NAME_OFFSET 12
//#else
//#define FILE_NAME_OFFSET 0
//#endif
List* readDirectoryContents(const char *dirname, const char *prefix) {
  DIR *dir;
  struct dirent *entry;
  List *l, *p;
  short iName=0;

  l = (List*) malloc(sizeof(List));
  p = l;
  p->next = NULL;

  dir = opendir(dirname);
  if(dir == NULL) {
    fprintf(stderr, "warning: cannot open directory '%s'\n", dirname);
    return l;
  }
  while((entry = readdir(dir)) != NULL) {
    char *name;
    if(prefix == NULL || strstr(entry->d_name+FILE_NAME_OFFSET, prefix) == entry->d_name+FILE_NAME_OFFSET) {
      if(entry->d_name[0+FILE_NAME_OFFSET] != '.') {
    	iName=strlen(entry->d_name+FILE_NAME_OFFSET);
		name = malloc(iName + 1);
		memcpy(name, entry->d_name+FILE_NAME_OFFSET, iName + 1);
		p->data = name;
		p->next = (List*) malloc(sizeof(List));
		p = p->next;
		p->next = NULL;
      }
    }
  }
  closedir(dir);
  return l;

}

void makeDirectory(const char *name) {
  int result;
  if(access(name, R_OK)) {
#ifndef WIN32
    result = mkdir(name, 0x1ff);
#else
    result = mkdir(name);
#endif
    if(result)
      printf("cannot create dir '%s': %s\n", name, strerror(errno));
  }
}
