// /bin/adm/_tar.c
// A Distortion mudlib command
// created by Beek Jan 11 94
// Note: this will only work with MudOS 0.9.18.19 or later.
// Converted to Orion by Zephyr

#define NONE     0
#define EXTRACT  1
#define CREATE   2
#define TABLE    3

#define VERSION "1.0" // Use minor number for notable changes
                      // major for stuff that breaks compatability
#define MAJOR_VERSION "1" // Keep this consistent with above

#define SYNTAX    "tar [-cxtvnf] tar_file_name [file_or_dir ...]\n"
#define CONFLICT  "tar: only one of the options c,t,x can be used.\n"
#define BADOPTION "tar: unknown flag '%c'.\n"

#include <std.h>

inherit DAEMON;

mapping *expand_dir(string tarfile,string file, string rel) {
   int i;
   string *files;
   mapping *ret;

/* Ok, so there's some code duplication here.  So sue me. */
   ret = ({ });
   files = get_dir(file+"/", -1);
   for (i=0;i<sizeof(files);i++) {
      if (file+"/"+files[i][0] != tarfile) {
         switch (files[i][1]) {
            case -2:
               ret += expand_dir(tarfile,file+"/"+files[i][0], rel+"/"+files[i][0]);
               break;
            case -1: /* BOGGLE */
               break;
            default:
               ret += ({ ([ "absolute" : file+"/"+files[i][0],
               "relative" : rel+"/"+files[i][0],
               "size"     : files[i][1] ]) });
               break;
         }
      }
   }
   return ret;
}

mapping *expand(string tarfile,string *files) {
   mapping *ret;
   int i,size;
   string file;
  
   ret = ({ });
   for (i=0;i<sizeof(files);i++) {
      file = resolv_path( "cwd",files[i]);
      if (file != tarfile) {
         switch (size = file_size(file)) {
            case -2:
               ret += expand_dir(tarfile,file,files[i]);
               break;
            case -1:
               write(sprintf("tar: No such file: %s",file));
               break;
            default:
               ret += ({ ([ "absolute" : file,
               "relative" : files[i],
               "size"     : size ]) });
               break;
         }
      }
   }
   return ret;
}

mapping build_table(string tarfile, string *files, int verbose) {
   int i;
   mapping ret;
   int index;
   string table;

   table = "";
   ret = expand(tarfile,files);
   for (i=0;i<sizeof(ret);i++) {
      table += sprintf("%s:%i:%i\n",ret[i]["relative"],index,ret[i]["size"]);
      index+=ret[i]["size"];
   }
   index = strlen(table);
   if (!index) {
      write("tar: No files in tar file.");
      return 0;
   }
   if (!write_file(tarfile,
      sprintf("// tar file: MudTar version %s\n(%i)\n",VERSION,index)))
      return 0;
   write_file(tarfile,table);
   return ret;
}

int do_create(string tarfile,string *files,int verbose) {
   mapping *table;
   int i;

   table = build_table(tarfile,files,verbose);
   if (!table)
      return notify_fail(sprintf("tar: Cannot write %s.\n",tarfile));
   for (i=0;i<sizeof(table);i++) {
      if (verbose) write(sprintf("Adding file %s.",table[i]["relative"]));
      write_file(tarfile,read_file(table[i]["absolute"]));
   }
   write(sprintf("tar: file %s created.",tarfile)); 
   return 1;
}

mapping load_table(string tarfile) {
   string table;
   string version,tmp;
   int start,length,index;
   string name;
   string *lines;
   int i,size;
   mapping ret;

   table = read_file(tarfile, 0, 2);
   if (sscanf(table,"// tar file: MudTar version %s\n(%d)",version,length)!=2) 
   {
      notify_fail("tar: Bad tar file format.");
   }
   if (sscanf(version,"%s.%s",version,tmp)!=2)
   {
      notify_fail("tar: Bad tar file version.\n");
   }
   if (version != MAJOR_VERSION)
   {
      notify_fail(sprintf("tar: Bad tar file version (file version = %s, program version = %s.\n",version,MAJOR_VERSION));
   }
   start = strlen(table);
   table = read_bytes(tarfile, start, length-1); // lose the last newline
   lines = explode(table,"\n");
   ret = allocate_mapping(sizeof(lines));
   for (i=0; i<sizeof(lines); i++) {
      sscanf(lines[i],"%s:%d:%d",name,index,size);
      ret[name] = ({ index+start+length, size });
   }
   return ret;
}

mapping find_in_table(string tarfile, string *files) {
   mapping tartable;
   mapping ret;
   int i;
   tartable = load_table(tarfile);
   if (!tartable) return 0;
   if (!files) return tartable;
   ret = ([ ]);
   for (i=0; i<sizeof(files); i++) {
      if (!undefinedp(tartable[files[i]])) {
         ret[files[i]] = tartable[files[i]];
      }
   }
   return ret;
}

int do_table(string tarfile,string *files,int verbose) {
   mapping table;
   int i;
   string *found;

   table = find_in_table(tarfile,files);
   if (!table) 
      return 0;
   found = keys(table);
   for (i=0;i<sizeof(found);i++) {
      write(found[i]);
   }
   return 1;
}

extract_file(string tarfile, int *index, string out, int safe) {
   string *path;
   string tmp;
   int i,fs;

   path = explode(out,"/");
   tmp = "";
   for (i=0; i<sizeof(path)-1; i++) {
      tmp += "/" + path[i];
      fs = file_size(tmp);
      if (fs>=0) {
         if (safe) {
            write(sprintf("File %s already exists.", tmp));
            return 0;
         } else {
            rm (tmp);
            fs = -1;
         }
      }
      if (fs==-1) {
         if (mkdir(tmp)==0) {
            write(sprintf("Attempt to create directory %s failed.",tmp));
            return 0;
         }
      }
   }
   return write_bytes(out, 0, read_bytes(tarfile, index[0], index[1]));
}

int do_extract(string tarfile,string *files,int verbose,int safe) {
   mapping table;
   string *found;
   int i;
   string path;

   path = (string)this_player()->get_path() + "/";
   table = find_in_table(tarfile, files);
   if (!table) return 0;
   found = keys(table);
   for (i=0;i<sizeof(found);i++) {
      if (verbose) write(sprintf("Extracting %s.",found[i]));
      if (!safe || file_size(path+found[i])==-1) {
         extract_file(tarfile,table[found[i]],path+found[i],safe);
      } else {
         write(sprintf("tar: %s exists.\n",found[i]));
      }
   }
   return 1;
}


int do_tar(string tarfile,string *files,int mode,int verbose,int safe) {
   int tmp;

   tarfile = resolv_path( "cwd", tarfile );
   tmp=file_size(tarfile);
   if (tmp==-2)
      return notify_fail(sprintf("tar: %s is a directory.\n",tarfile));

   switch (mode) {
      case CREATE:
         if (tmp>=0) {
            if (safe)
               return notify_fail(sprintf("tar: %s already exists.\n",tarfile));
            else
               rm(tarfile);
         }
         return do_create(tarfile, files, verbose);
      case TABLE:
         if (tmp==-1)
            return notify_fail(sprintf("tar: no such file %s.\n",tarfile));
         return do_table(tarfile, files, verbose);
      case EXTRACT:
         if (tmp==-1)
            return notify_fail(sprintf("tar: no such file %s.\n",tarfile));
         return do_extract(tarfile, files, verbose, safe);
   }
}

int cmd_tar( string arg ) {
   int verbose, mode, safe;
   int i;
   string options,tarfile,rest;
   string *files;

   seteuid(geteuid(previous_object()));
  
   if (!arg) return notify_fail(SYNTAX);
   if (sscanf(arg,"%s %s %s",options,tarfile,rest)!=3) {
      if (sscanf(arg,"%s %s",options,tarfile)!=2)
         return notify_fail(SYNTAX);
      rest = 0;
   }
   if (rest) files = explode(rest," ");

   for (i=0;i<strlen(options);i++) switch(options[i]) {
      case '-':
         if (i==0) break;
         return notify_fail(SYNTAX);
      case 'x':
         if (mode) return notify_fail(CONFLICT);
         mode = EXTRACT;
         break;
      case 'c':
         if (mode) return notify_fail(CONFLICT);
         mode = CREATE;
         break;
      case 't':
         if (mode) return notify_fail(CONFLICT);
         mode = TABLE;
         break;
      case 'v':
         verbose = 1;
         break;
      case 'n':
         safe = 1;
         break;
      case 'f':
         break;
      default:
         return notify_fail(sprintf(BADOPTION,options[i]));
   }

   if (mode == NONE)
      return notify_fail("tar: no mode specified (c, t, or x)\n");

   return do_tar(tarfile, files, mode, verbose, safe);
}

int help() {
   string compile;
   
   compile = "Syntax: "+SYNTAX;
   compile += "\n";
   compile += "This command creates and expands tar files, much like the UNIX tar command.  ";
   compile += "Note that MUD tar files of ASCII files, unlike UNIX tar files, contain no ";
   compile += "control characters, and can be mailed, edited, etc.\n";
   compile += "\n";
   compile += "The tar command operates in one of three modes:\n";
   compile += "Create Mode:\n";
   compile += "Example:   tar -c my_stuff.tar ~ \n";
   compile += "\n";
   compile += "creates a tar file name my_stuff.tar in the current directory, which contains ";
   compile += "all the files in your home directory.\n";
   compile += "\n";
   compile += "Extract Mode:\n";
   compile += "Example: tar xvf my_stuff.tar\n";
   compile += "\n";
   compile += "extracts a previously created tar file.  Be careful not to overwrite existing ";
   compile += "files.  The 'n' flag, if included, makes tar fail if the file previously ";
   compile += "exists.\n";
   compile += "\n";
   compile += "Table Mode:\n";
   compile += "Example: tar -vt some_tar_file\n";
   compile += "\n";
   compile += "prints a list of the files in a tar file\n";
   compile += "\n";
   compile += "Options:\n";
   compile += "v: makes tar rather noisy\n";
   compile += "n: don't overwrite files\n";
   compile += "\n";
   compile += "Notes:\n";
   compile += " - Like the UNIX command, the '-' is optional\n";
   compile += " - MUD tar is smarter than some UNIX tar's (sunOS in particular) which will\n";
   compile += "   fill your file system if your tar is recursive.  This means that the\n";
   compile += "   the following works correctly:\n";
   compile += "   tar cvf ~/my_dir.tar ~ \n";
   message( "help", compile, this_player() );
   return 1;
} 
