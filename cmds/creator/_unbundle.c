//   /bin/dev/_unbundle.c
//   A command to unbundle bundle files.  similar to tar, but bundle files
//   can be unbundled on unix by "sh"ing the file.
//   By Valodin

#include <std.h>

inherit DAEMON;

void unpack(string path)
{
  string *lines;
  string current_file, tmp;
  int i, lsz;

  lines = read_database(path);
  i = 0; lsz = sizeof(lines);
  while(i < lsz)
  {
    if(sscanf(lines[i++], "echo %s 1>&2", tmp) != 1)
      continue;
    current_file = resolv_path((string)this_player()->get_path(), tmp);
    write("Unpacking " + current_file + "\n");
    i++;   /* skip sed line */
    rm(current_file);
    while(lines[i][0] == '-')
    {
      write_file(current_file, lines[i][1..strlen(lines[i])] + "\n");
      i++;
    }
    i++;  /* skip End line */
  }
}

int cmd_unbundle(string str)
{
  string tmp;

  notify_fail("Usage: unbundle <file>\n");
  if(!str)
    return 0;
  tmp = resolv_path((string)this_player()->get_path(), str);
  write("Trying to unbundle " + tmp + "\n");
  unpack(tmp);
  return 1;
}

int help()
{
  write("Command: unbundle\n"
	"Syntax: unbundle <filename>\n\n"
	"This unpacks files that have been created using bundle.  They can "
	"also be\nunpacked on a unix system by \"sh\"ing the file.\n");
  return 1;
}
