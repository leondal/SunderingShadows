//ACTIVELY USED
//This functionality already exists in the simul-efun arrange_string.c

//Coded by Lujke. For stripping a string of its color codes. 
//There may be easier ways to do this, but this should work.

#include <std.h>
inherit DAEMON; 

string stripcolors(string str){
  str = replace_string(str, "%^RESET%^", "");
  str = replace_string(str, "%^BOLD%^", "");
  str = replace_string(str, "%^BLACK%^", "");
  str = replace_string(str, "%^WHITE%^", "");
  str = replace_string(str, "%^RED%^", "");  
  str = replace_string(str, "%^ORANGE%^", "");
  str = replace_string(str, "%^YELLOW%^", "");
  str = replace_string(str, "%^GREEN%^", "");
  str = replace_string(str, "%^CYAN%^", "");
  str = replace_string(str, "%^BLUE%^", "");
  str = replace_string(str, "%^MAGENTA%^", "");
  str = replace_string(str, "%^B_RED%^", "");
  str = replace_string(str, "%^B_BLUE%^", "");
  str = replace_string(str, "%^B_CYAN%^", "");
  str = replace_string(str, "%^B_ORANGE%^", "");
  str = replace_string(str, "%^B_YELLOW%^", "");
  str = replace_string(str, "%^B_GREEN%^", "");
  str = replace_string(str, "%^B_MAGENTA%^", "");
  str = replace_string(str, "%^B_BLACK%^", "");
  str = replace_string(str, "%^B_WHITE%^", "");
  str = replace_string(str, "%^FLASH%^", "");
  str = replace_string(str, "%^INITTERM%^", "");
  str = replace_string(str, "%^RESET%^", "");
  str = replace_string(str, "%^WINDOW%^", "");
  str = replace_string(str, "%^ENDTERM%^", "");
  return str;
}

string decode(string str){
  str = replace_string(str, "%^RESET%^", "RESET");
  str = replace_string(str, "%^BOLD%^", "BOLD");
  str = replace_string(str, "%^BLACK%^", "BLACK");
  str = replace_string(str, "%^WHITE%^", "WHITE");
  str = replace_string(str, "%^RED%^", "RED");  
  str = replace_string(str, "%^ORANGE%^", "ORANGE");
  str = replace_string(str, "%^YELLOW%^", "YELLOW");
  str = replace_string(str, "%^GREEN%^", "GREEN");
  str = replace_string(str, "%^CYAN%^", "CYAN");
  str = replace_string(str, "%^BLUE%^", "BLUE");
  str = replace_string(str, "%^MAGENTA%^", "MAGENTA");
  str = replace_string(str, "%^B_RED%^", "B_RED");
  str = replace_string(str, "%^B_BLUE%^", "B_BLUE");
  str = replace_string(str, "%^B_CYAN%^", "B_CYAN");
  str = replace_string(str, "%^B_ORANGE%^", "B_ORANGE");
  str = replace_string(str, "%^B_YELLOW%^", "B_YELLOW");
  str = replace_string(str, "%^B_GREEN%^", "B_GREEN");
  str = replace_string(str, "%^B_MAGENTA%^", "B_MAGENTA");
  str = replace_string(str, "%^B_BLACK%^", "B_BLACK");
  str = replace_string(str, "%^B_WHITE%^", "B_WHITE");
  str = replace_string(str, "%^FLASH%^", "FLASH");
  str = replace_string(str, "%^INITTERM%^", "INITTERM");
  str = replace_string(str, "%^RESET%^", "RESET");
  str = replace_string(str, "%^WINDOW%^", "WINDOW");
  str = replace_string(str, "%^ENDTERM%^", "ENDTERM");
  return str;
}

string decode_file(string file_name){
  string str;
  if (!file_exists(file_name))
  {
    tell_object(TP, "File " + file_name + " does not exist. Please try again");
    return;
  }
  str = read_file(file_name);
  str = decode(str);
  return str;
}
