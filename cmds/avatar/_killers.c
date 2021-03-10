//killers
//simple enough.....

#include <std.h>
#include <dirs.h>

inherit DAEMON;

int ampersand(string str) {
  string junk1, junk2;
  if (sscanf(str, "%swas killed by%s",junk1, junk2) == 2 ) return 1;
  if (sscanf(str, "%s submitted %s",junk1, junk2) == 2 ) return 1;
  if (sscanf(str, "%s$&$%s",junk1, junk2) == 2 )
    return 1;
  else
    return 0;
}
int cmd_killers(string str) {
  string killers_buffer, *killers_array;
  int lines;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

  if (stringp(str)) {
	write("%^BOLD%^%^RED%^                   The following killing has occured");
	write("%^BOLD%^                       You must decide upon them");
	write("%^BOLD%^%^BLUE%^      <-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=->");

	tail("/log/killers");
	write("%^BOLD%^%^BLUE%^      <-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=->");
	return 1;
  } else {

// magic needs to be done here.
    if(!(lines=atoi((string)TP->getenv("LINES"))))
      lines = 20;
  killers_buffer = read_file("/log/killers");
  if(!strlen(killers_buffer) || killers_buffer == "") { return 1; }
  killers_array=explode(killers_buffer,"\n");
  killers_array=filter_array(killers_array,"ampersand",TO);
  if (sizeof(killers_array) > lines) {
    killers_array = killers_array[sizeof(killers_array)-lines..sizeof(killers_array)];
  }
  TP->more(killers_array);
 return 1;
  }
}
