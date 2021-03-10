#include <std.h>
inherit DAEMON;


void update_directory(string *dirs)
{
    
    
}



string get_files(string dir)
{
    int i;
    string *files=({}),tmp=({});
    
    if(!tmp = get_dir(dir)) { return ({}); }
    
    for(i=0;i<sizeof(tmp);i++)
    {
        if(get_dir(tmp[i]+"/")) { continue; }
        files += ({tmp[i]});        
    }
    
    if(!sizeof(files)) { return ({}); }
    
    return files;  
}


string *get_directories(string dir)
{
    int i;
    string *dirs=({}),tmp=({});
    
    if(!tmp = get_dir(dir)) { return ({}); }
    
    for(i=0;i<sizeof(tmp);i++)
    {
        if(!get_dir(tmp[i]+"/")) { continue; }
        dirs += ({tmp[i]});        
    }
    
    if(!sizeof(dirs)) { return ({}); }
    
    return dirs;    
}


void update_files(string *files)
{
    
    
}

void begin(mixed map)
{
    mapping info=([]);
    string *dirs,*files,path;
    int i;
    
    if(!mapp(map))
    {
        path = "";
    }
    else
    {
        path = map["path"];
    }
    
    
    
    
    
}


int cmd_updateall(string str)
{
    tell_object(TP,"Beginning..  please don't use this command again until it finishes.");
    begin(([]));    
}

/*
int cmd_dirupdate(string str) {
  string file, tmp, *dir;
  object ob;
  int i;

  if(!str) {
  	file = resolv_path((string)this_player()->get_path(), str);
  } else
	file = str;
  if(file_size(file) != -2) {
    notify_fail(file + " is not a directory.\n");
    return 0;
  }
  dir = get_dir(file + "/*.c");
  for(i = 0; i < sizeof(dir); i++) {
     if(!catch(ob = find_object_or_load(file + "/" + dir[i]))) {
       write( "Updating..." + file + "/" + dir[i] );
      catch(ob->remove());
     }
     else write("Failed to update " + file + "/" + dir[i]);
   }
   write("Update done.\n");
   return 1;
}

int help()
{
  write( @EndText
Syntax: dirupdate <directory>
Effect: updates all objects in <directory>
See also: update, dir
EndText
  );
  return 1;
  
  
  
  
  catch( ob-> remove() );
  if( !ob )
  {
    write( a + " has been removed.\n" );
    return 1;
  }
  catch( destruct( ob ) );

  
  
  
  
  
  
  
}*/



