//      /bin/system/_grep.c
//      from the Nightmare Mudlib
//      searches for an expression in files
//      created by Descartes of Borg 930822

#include <std.h>

inherit DAEMON;

string * process_dir( string myDir, string exp, string * all_files);
void process_files(string * all_files, object tp, string str, string exp, string output);

mapping grepResults = ([]);

int cmd_rgrep2(string str) {
  string output, exp, file, tmp;
  string *files = ({});
  int i, j, max;
  string *all_file_names = ({ });
  grepResults = ([]);

  return notify_fail("Garrett thinks this isn't done yet");
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
 
  all_file_names =  process_dir(file, exp, ({ }) );
  call_out("process_files",1,all_file_names, TP, "", exp, output);
  seteuid(getuid());
  //  grepResults = ([]);
  return 1;
}

void process_files(string * all_files, object tp, string str, string exp, string output) {
  int max;
  //  write(identify(all_files));
  max = sizeof(all_files);
  if (max) {
    if (stringp(all_files[0])) {
      grepResults[all_files[0]] =regexp(explode(read_file(all_files[0])+"", "\n"), exp);
      if(!sizeof(grepResults[all_files[0]])) {
	map_delete(grepResults, all_files[0]);
      } else {
	str += all_files[0] +":\n"+implode(grepResults[all_files[0]],"\n")+"\n\n";
      }
    }

    call_out("process_files",1,all_files[1..max], tp, str, exp, output);
    return;
  }
  write("Done.");
  if(!(strlen(str)))
    return write("No matches found.\n");

  else {
    if(output) {
      if(!write_file(output, str))
	message("system", "Failed to write to: "+output, tp);
      else message("system", "Grep sent to: "+output, tp);
    } else tp->more(explode(str,"\n"));
  }
}

//Making this recurse is gonna be the fun part.
string * process_dir( string myDir, string exp, string * all_files){
  string *files;
  int i;
  
  //  write(identify(myDir) + identify(exp)+identify(all_files));
  files = get_dir(myDir);
  
  if(sizeof(files) <= 0) {
    //  write("Empty dir case:");
    return all_files;
  }
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
      if (sizeof(all_files))
	all_files += process_dir(myDir+files[i]+"/", exp, copy(all_files));
      else
	all_files = process_dir(myDir+files[i]+"/", exp, copy(all_files));

      continue;
    }
    //Its not a dir, rip it up.
    if (sizeof(all_files))
      all_files += ({ myDir+files[i] });
    else
      all_files = ({ myDir+files[i] });
    
    //        grepResults[myDir+files[i]] =regexp(explode(read_file(myDir+files[i])+"", "\n"), exp);
    // if(!sizeof(grepResults[myDir+files[i]]))
    //    map_delete(grepResults, myDir+files[i]);
  }
  exp = replace_string(exp,"*",".*");
  exp = replace_string(exp,"?",".");
  
  all_files = regexp(".+/"+exp,all_files);  
  return all_files;
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
