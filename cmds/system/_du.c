/*
 * du - Disk Usage
 * shows usage (in K) in all directories below a specified point
 * without args, the default is the current dir
 * 
 * Written by: Gunn @ TMI (01/22/92)
 *
 */

#include <std.h>

inherit DAEMON;

#define MAX_RECURSE 4

int disk_usage(string path, int level);
int cmd_du(string path);

int disk_usage(string path, int level) 
{
 int i, total, num;
 string *dir;

 if (level>MAX_RECURSE) return 0;

 total= file_size(path);
 if (total == -1)
   {
    write("Cannot access: " + path + "\n");
    return 0;
   }
 if (total == -2)
   {
    total= 0;
    dir = get_dir(path + "/");
    if (dir)
      {
       num = sizeof(dir);
       for (i=0; i<num; i++) total += disk_usage(path+"/"+dir[i], level+1);
      }
/* series of fixes by Valodin 1-19-93 */
    message("system", sprintf("%d Kbytes   %d bytes   %s", (1+total/1024),
      total, path), this_player());
   }
 return total;
}

int cmd_du(string path)
{
 seteuid(getuid(previous_object()));
 if (!path) path = (string)this_player()->get_path();
 else path = resolv_path((string)this_player()->get_path(),path);
 disk_usage(path,0);
 return 1;
}

int help()
{
 write("du - Disk Usage\n\n");
 write(" Syntax: du [path]\n\n");
 write(" 'du' recursively scans directories, starting from the specified\n" +
       " path. File sizes are added up, and a total 'K' amount for each\n" +
       " directory is displayed. If no path is supplied, the current\n" +
       " directory is used.\n\n");
 return 1;
}

