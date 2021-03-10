/*
// The new, more efficient, improved ls command.
// Thanks to Huthar and Wayfarer for this one.
   Plura 930119, I changed size/=1000 into size/=1024
		 I added the '*' in front of loaded objects.
		 I added the write() with totsize and # of files.
   write() changed to message() by Valodin, August 19, 1993
   Borrowed with permission from Dragonsrest, by Soulcatcher.
*/
#include <std.h>

inherit DAEMON;

#define T_CONST 60*60*24*30
string spaces;
int tfiles,tsize,tdirs; /* too many local variables... */

varargs int do_llm(mixed path, object act_ob, int show_dots, string real_path)
{
  string *files;
  string *Files,*Dirs;
  int index,j,x,y,rows,cols,l,length,num,size,i;
  int mtime, ltime;
  string *wcfiles;
  string string_path, temp;
  
  if(!act_ob)
    act_ob = previous_object();
  
  tsize = tfiles = tdirs = 0;
  spaces = "                                                                               ";
  seteuid(getuid(act_ob));
  if(!pointerp(path))
    {
      size = file_size(path);
      
      if (size >= 0) {
	mtime= stat(path)[1];
	ltime= stat(path)[2];
      } else {
	mtime = ltime = 0;
      }
      if (size > -1) {
	size /= 1024;
	if (size == 0) size = 1;
	files = explode(path,"/");
	path = files[sizeof(files)-1];
	temp = arrange_string(ctime(mtime),26);
	if (ltime)
	  temp += "%^BOLD%^%^GREEN%^"+ arrange_string(ctime(ltime),26);
	
        if (!mtime || ((time()-mtime) < T_CONST) )
	write( size + " " + path+"   " + temp);
	return 1;
      }
      
      if (path != "/")
	path += "/";
      if( !((int)master()->valid_read(path, this_player())) ) {
	message("system", path+": permission denied", this_player());
	return 1;
      }
      files = get_dir(path);
    }
  else
    {
      files = path[1];
     write("path :="+identify(path));
      path = path[0][0] + "/";
    }
  if(!show_dots)
    files = filter_array(files, "remove_dots", this_object());
  
  if (!files) {
    size = file_size(path);
    if (size == -2) {
      return 1;
    }
    if (size == -1) {
      notify_fail("No such file or directory.\n");
      return 0;
    }
    message("system", size + " " + path, this_player());
	return 1;
  }
    num = sizeof(files);
    for (index = 0; index < num; index++) {
      i = strlen(files[index]);
      if (i > length) length = i;
    }
    length ++;
    cols = 1;
  // One column, please.
    rows = num / cols;
    if (rows * cols < num)
      rows++;
    message("system", path+":", this_player());
    for (y = 0; y < rows; y++) {
      temp = "";
      for (x = 0; x < cols; x++) {
	index = x * rows + y;
	if (index > num - 1) 
	  break;
	size = file_size((string)path + files[index]);
	l = strlen(files[index]);
	switch(size) {
	case -2:
          mtime = stat((string)path+files[index],-1)[0][2];
	  temp += "     %^BOLD%^%^BLUE%^"+arrange_string(files[index]+"%^RESET%^/",length+3);
	  temp += arrange_string(ctime(mtime),26);
	  tdirs++;
	  l++;
	  break;
	case -1:
	  temp += "   %^RED%^%^BOLD%^- " + files[index]+"%^RESET%^";
	  break;
	default:
	  if (size >= 0) {
	    mtime= stat((string)path + files[index])[1];
	    ltime= stat((string)path + files[index])[2];
	  } else {
	    mtime = ltime = 0;
	  }
        if (!mtime || ((time()-mtime) < T_CONST) )
	  tfiles++;
        if (!mtime || ((time()-mtime) < T_CONST) )
	  tsize += size;
	  size /= 1024;
	  if (size == 0) size = 1;
	  if (size < 10) temp += " ";
	  if (size < 100) temp += " ";
	  if(find_object(path+files[index]))
	    temp += "%^GREEN%^%^BOLD%^*";    /* Plura 930119  */
	  else
	    temp += " ";
         temp += size + " " + arrange_string(files[index],length+3) + "%^RESET%^";

	  temp += arrange_string(ctime(mtime),26);
	  if (ltime)
	    temp += "%^BOLD%^%^GREEN%^"+ arrange_string(ctime(ltime),26);
	  break;
	}
	if (length - l > 0)
	  temp += spaces[1 .. (length - l)];
      }
      //      message("Nsystem", "\n", this_player());
        if (!mtime || ((time()-mtime) < T_CONST) )
      write(temp);
    }
    message("system", "A total of "+tsize+" bytes in "+tfiles +
	    " file" + ((tfiles != 1) ? "s." : ".") +
	    "  ("+tdirs+" director"+((tdirs != 1)?"ies)":"y)"), this_player());
    return 1;
}

int cmd_llm(string path)
{
  string *Files,*Dirs;
  int i, num;
  string *wcfiles;
  mixed *tmp;
  int show_dots;
  string str2;
  object act_ob;
  
  act_ob = this_player();
  
  seteuid(getuid(act_ob));
  if(path && (path == "-a" || sscanf(path,"-a %s",str2)))
    {
      show_dots = 1;
      path = str2;
    }
  
  wcfiles = (string *)act_ob->wild_card(path);
  
  if (!wcfiles || !sizeof(wcfiles))
    {
      message("system", "No such file or directory.", this_player());
      return 1;
    }
  num = sizeof(wcfiles);
  if(num == 1)
    {
      do_llm(wcfiles[0], act_ob, show_dots);
      return 1;
    }
  
  tmp = path_file(wcfiles);
  Files = filter_array(wcfiles, "is_file", this_object());
  Dirs = wcfiles - Files;

  if(Files)
    do_llm(path_file(Files), act_ob, show_dots);
  if(Dirs)
    {
      for(i = 0; i < sizeof(Dirs); i++)
	{
	  message("system", Dirs[i]+":", this_player());
	  do_llm(Dirs[i],act_ob, show_dots);
	}
    }
  return 1;
}

int is_file(string file)
{
  return(file_size(file) >= 0);
}

int remove_dots(string file)
{
  if(file[0] == '.')
    return 0;
  return 1;
}

int help()
{
  write( @EndText
	 Syntax: ls <directory>
	 Effect: Lists the names of the files in <directory>
	 Columns are size, filename, last modification date, and last loaded date (if applicable)
	 See also: cd, more, ed, pwd
EndText
	 );
  return 1;
}
