//      /bin/system/_grep.c
//      from the Nightmare Mudlib
//      searches for an expression in files
//      created by Descartes of Borg 930822

#include <std.h>

inherit DAEMON;

void process_dir( string file, string exp );

mapping grepResults = ([]);

int cmd_rgrep(string str) {
  string output, exp, file, tmp;
  string *files = ({});
  int i, j, max;

  grepResults = ([]);

  notify_fail("Correct syntax: <rgrep '[pattern]' [file] (> [output])>\n");
  if(!str) return 0;

  if(sscanf(str, "%s > %s", tmp, output) == 2) {
    if(output[0] != '/')
      output = (string)previous_object()->get_path()+"/"+output;
    str = tmp;
  } else {
    output = 0;
  }

  if(sscanf(str, "'%s' %s", exp, file) != 2 && sscanf(str, "%s %s", exp, file) != 2) {
    return 0;
  }

  seteuid(getuid(previous_object()));
  if(file[0] != '/'){
      file = (string)previous_object()->get_path()+"/"+file;
  }
  file = previous_object()->get_path()+"/";
  //tell_object(TP, "Using dir: "+file);

  process_dir(file, exp);

  //We have every file that matches in borg.
  if(!(max = sizeof(files = keys(grepResults))))
    return notify_fail("No matches found.\n");
  else {
    for(i=0, str = ""; i<max; i++)
      str += files[i] +":\n"+implode(grepResults[files[i]],"\n")+"\n\n";
  }
  
  if(output) {
    if(!write_file(output, str))
      message("system", "Failed to write to: "+output, this_player());
    else message("system", "Grep sent to: "+output, this_player());
  } else TP->more(explode(str,"\n"));
  
  seteuid(getuid());
  grepResults = ([]);
  return 1;
}

//Making this recurse is gonna be the fun part.
void process_dir( string myDir, string exp ){
    string *files;
    int i;

    files = get_dir(myDir);
    
    if(sizeof(files) <= 0) return;
    for( i = 0; i<sizeof(files); i++){
        if( files[i] == ".." || files[i] == "." ) continue;
    if( file_size(myDir+files[i]) == 0 ) {
       write("%^BOLD%^%^RED%^"+myDir+files[i]+": Empty File.");
       continue;
       //ignore empty files.
     }
    if( file_size(myDir+files[i]) == -1 ) {
       write("%^BOLD%^%^RED%^"+myDir+files[i]+": Access Denied.");
       continue;
       //ignore empty files.
     }

        if( file_size(myDir+files[i]+"/") == -2 ) {  //if its a directory
            process_dir(myDir+files[i]+"/", exp);
            continue;
        }
        //Its not a dir, rip it up.
        grepResults[myDir+files[i]] =regexp(explode(read_file(myDir+files[i])+"", "\n"), exp);
        if(!sizeof(grepResults[myDir+files[i]]))
            map_delete(grepResults, myDir+files[i]);
    }

    return;
}

void help() {
  message("help",
          "Syntax: <rgrep '[pattern]' [whatever] (> [redirect])>\n\n"
          "Just like grep but recurses down through all subdirs."
          "The second argument is ignored until I can fix that part."
          "currently it will start in your current dir and search every"
          "dir until it can recurse no more.\n\n"
          "Searches a file or group of files for a specific pattern.  "
          "If the pattern is a single word, then no '' is needed.  Patterns "
          "of more than one word however, need to be enclosed in ''.  "
          "You may redirect the output of the grep to to a file using the >."
          "\n\nSee also: cd, ls, mv, pwd, rm", this_player()
         );
}
