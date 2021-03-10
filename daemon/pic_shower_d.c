#include <std.h>
#include <security.h>
#include <daemons.h>
#include "/daemon/pictures/pictures.h"
#define SAVE_FILE "/daemon/save/pic_shower" 
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "pic_shower_log"

#define SUBSTITUTIONS (["m": "%^RESET%^%^MAGENTA%^", "M": "%^BOLD%^%^MAGENTA%^", "r": "%^RESET%^%^RED%^", "R": "%^RESET%^%^BOLD%^%^RED%^", "y": "%^RESET%^%^ORANGE%^", "Y": "%^RESET%^%^BOLD%^%^ORANGE%^", "g": "%^RESET%^%^GREEN%^", "G": "%^BOLD%^%^GREEN%^", "b": "%^RESET%^%^BLUE%^", "B": "%^RESET%^%^BOLD%^%^BLUE%^", "c": "%^RESET%^%^CYAN%^", "C": "%^BOLD%^%^CYAN%^", "d": "%^RESET%^%^BLACK%^", "D": "%^BOLD%^%^BLACK%^", "w": "%^RESET%^%^WHITE%^", "W": "%^BOLD%^%^WHITE%^", "a": "%^B_MAGENTA%^", "e": "%^B_RED%^", "i": "%^B_ORANGE%^", "o":"%^B_GREEN%^", "u": "%^B_BLUE%^", "A": "%^B_CYAN%^", "E": "%^B_WHITE%^", "I": "%^B_BLACK%^"])

void showpic(string picname, object who){
  string * pic;
  switch(picname)
  {
  case "waterfall":
    pic = WATERFALL;
    break;
  case "waterfall2":
    pic = colour_picture(WATERFALL2, WFCOL2);
//    pic = colour_picture(WATERFALL2, WFBACK2);
    break;
  case "waterfall3":
    pic = colour_picture(WATERFALL3, WFCOL3);
    break;
  case "canoefall":
    pic = colour_picture(CANOEFALL, FALLCOL);
    break;
  case "canoefall2":
    pic = colour_picture(CANOEFALL2, FALLCOL2);
    break;
  case "islandbeach":
    pic = colour_picture(ISLAND, ISLANDCOL);
    break;
  }
  show_picture(pic, who);
}

void show_picture(string * picture, object who){
  string line;
  if (!objectp(who) && objectp(TP)) who = TP;
  foreach(line in picture)
  {
    tell_object(who, line);
  }
}

varargs string * colour_picture(string * picture, string * colour_map, string * background_map){
  string line, colour_line, ch, newline, * ks, * newpic, background_line;
  int i,j, k;
  ks = keys(SUBSTITUTIONS);
  newpic = ({});
  for (i=0;i<sizeof(picture);i++)
  {
    colour_line = "";
    background_line = "";
    newline = picture[i];
    if (sizeof(colour_map)>i)
    {
      colour_line = colour_map[i];
    }
    if (sizeof(background_map)>i)
    {
      background_line = background_map[i];
    }
    if (strlen(colour_line)>0) 
    {
      for (j=sizeof(colour_line)-1;j>=0;j--)
      {
        k = j;
        ch = colour_line[j..j];
        if (member_array(ch, ks)!=-1)
        {
          newline = "/daemon/str_insert_d"->brute_insert_string(newline, SUBSTITUTIONS[ch], j);
          k += strlen(SUBSTITUTIONS[ch]);
        } 
      }
    }
    if (strlen(background_line)>0) 
    {
      for (j=sizeof(background_line)-1;j>=0;j--)
      {
        ch = background_line[j..j];
        if (member_array(ch, ks)!=-1)
        {
          newline = "/daemon/str_insert_d"->brute_insert_string(newline, SUBSTITUTIONS[ch], );
        } 
      }
    }
    newpic = newpic + ({newline});
  }
  return newpic;
}
