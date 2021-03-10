/* changelog.c
* author: wayfarer
* date: 12/8/91
* note: adds an entry into the DONE file in the named domain
* bugs: no error checking on non-existant domains
* Modified for the TMI distribution mudlib by Buddha (1/9/92)
* Changed to fit into the /bin command structure, setting its
* euid to the current user, then self-destructs to reduce memory use.
* Changed query_real_name to query_rname for Nightmare (93-05-26) Pallando
*/
#include <std.h>

inherit DAEMON;

private string *files, *coders;

void create() {
    ::create();
    coders = ({});
    files = ({});
}

int get_ref() { 
	return member_array((string)this_player()->query_name(), coders);
}
void push_coder(string file) {
        string who;
        who = (string)this_player()->query_name();
        coders += ({ who });
	files += ({ file });
}
void pop_coder(int ref) {
	coders -= ({ coders[ref] });
	files -= ({ files[ref] });
}
int cmd_clog(string path) {
   string who, tmp;
   who = (string)this_player()->query_name();
   if (!path)  path = (string)this_player()->get_path();
   path = resolv_path((string)this_player()->get_path(), path);
   push_coder(path + "/DONE");
   write("Editing DONE for " + path + "\n");
   this_player()->edit("/tmp/changelog_"+who,"changelog_done",
		this_object());
   return 1;
}

void changelog_done() {
   string old, msg, infile, clfile;
   string *lines, *newlines;
   int count, i, j;
   
   infile = (string)this_player()->query_edit_filename();
    seteuid(geteuid(this_player()));
   msg = read_file(infile);
   if (msg == "" || !msg) return;
   clfile = files[get_ref()];
   old = read_file(clfile);
   rm(clfile);
   write_file(clfile,ctime(time()) + "   " +
      (string)this_player()->query_rname() + "   (" +
      (string)this_player()->query_cap_name() + " at " + 
      query_ip_name(this_player()) + ")\n\n\t* ");
   lines = explode(msg," ");
   if (lines)
      for (i = 0; i < sizeof(lines); i++) {
      newlines = explode(lines[i],"\n");
      if (!newlines) newlines = ({lines[i]});
      for (j = 0; j < sizeof(newlines); j++) {
         if (newlines[j] == 0)
            continue;
         if (count + strlen(newlines[j]) >= 65) {
            write_file(clfile,"\n\t");
            count = 0;
           }
         write_file(clfile,newlines[j] + " ");
         count += strlen(newlines[j]) + 1;
         }
   }
   write_file(clfile,"\n\n");
   if (old)
      write_file(clfile, old);
   rm(infile);
   seteuid(getuid());
   write("Updated DONE.\n");
   pop_coder(get_ref());
}

void abort() {
   write ("changelog aborted\n");
   return;
}
int help() {
    write("Usage: changelog <directory>\n");
    write("\n\tUpdates the DONE file in either the current directory\n");
    write("(If no directory is specified) or the specified directory.\n");
    write("This will put you in an editor, like the one on the bulletin\n");
    write("boards.  This is useful for keeping a record of the changes\n");
    write("that have been made in the directory in question.\n");
    return 1;
}


