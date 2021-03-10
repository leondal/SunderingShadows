#include <std.h>

/**
 * Converts NightMare color codes to html4
 *
 * @param str - string to convert
 * @return string with html code.
 */
public string convertFromInput(string str){
   if(!stringp(str)) return str;
   str = replace_string(str,"%^RESET%^","</font></b></u></font><font color=\"#FFFFFF\">");
   str = replace_string(str,"%^RED%^","</font><font color=\"#FF0000\">");
   str = replace_string(str,"%^GREEN%^","</font><font color=\"#00FF00\">");
   str = replace_string(str,"%^BLUE%^","</font><font color=\"#0088FF\">");
   str = replace_string(str,"%^YELLOW%^","</font><font color=\"#FFFF33\">");
   str = replace_string(str,"%^BLACK%^","</font><font color=\"#555555\">");
   str = replace_string(str,"%^WHITE%^","</font><font color=\"#FFFFFF\">");
   str = replace_string(str,"%^ORANGE%^","</font><font color=\"#EEEE00\">");
   str = replace_string(str,"%^MAGENTA%^","</font><font color=\"#EE00EE\">");
   str = replace_string(str,"%^CYAN%^","</font><font color=\"#00BBBB\">");
   str = replace_string(str,"%^BOLD%^","<b>");
   str = replace_string(str,"%^ULINE%^","<u>");
   str = replace_string(str,"%^B_BLUE%^","");
   str = replace_string(str,"%^B_CYAN%^","");
   str = replace_string(str,"%^B_YELLOW%^","");
   str = replace_string(str,"%^B_MAGENTA%^","");
   str = replace_string(str,"%^B_RED%^","");
   str = replace_string(str,"%^B_GREEN%^","");
   str = replace_string(str,"%^B_ORANGE%^","");
   str = replace_string(str,"%^B_BLACK%^","");
   str = replace_string(str,"%^B_WHITE%^","");
   str = replace_string(str,"%^FLASH%^","");
   str = replace_string(str,"\n\n","\n<br>");

   return str;
}

public string convertToInput(string str){

   if(!stringp(str)) return str;

   str = replace_string(str,"</font></b></u>","%^RESET%^");
   str = replace_string(str,"</font><font color=\"#FF0000\">","%^RED%^");
   str = replace_string(str,"</font><font color=\"#00FF00\">","%^GREEN%^");
   str = replace_string(str,"</font><font color=\"#0088FF\">","%^BLUE%^");
   str = replace_string(str,"</font><font color=\"#FFFF33\">","%^YELLOW%^");
   str = replace_string(str,"</font><font color=\"#555555\">","%^BLACK%^");
   str = replace_string(str,"</font><font color=\"#FFFFFF\">","%^WHITE%^");
   str = replace_string(str,"</font><font color=\"#EEEE00\">","%^ORANGE%^");
   str = replace_string(str,"</font><font color=\"#EE00EE\">","%^MAGENTA%^");
   str = replace_string(str,"</font><font color=\"#00BBBB\">","%^CYAN%^");
   str = replace_string(str,"<b>","%^BOLD%^");
   str = replace_string(str,"\n<br>","\n\n");

   return str;
}
