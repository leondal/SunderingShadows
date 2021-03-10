/*
// file: /std/player/history.c
// author: Portals (wayfarer and huthar)
// last modified: 1992/03/08 - Truilkan@TMI
*/

#include "security.h"

private static string *history_queue;
private static int cmd_num, ptr;
private static int max;

int query_cmd_num() { return cmd_num ? cmd_num : 1; }
int query_ptr() { return ptr; }
int query_max() { return max; }
string *query_history() {
    if(geteuid(previous_object()) != geteuid() &&
      geteuid(previous_object()) != UID_USERACCESS) return ({});
    return history_queue;
}

void alloc(int size)
{
    max = size;
    if (max)
       history_queue = allocate(max);
    cmd_num = 1;
}

void enqueue(string str)
{
   string tmp;

   if(!max)
      return;
   history_queue[ptr++] = str;
   cmd_num++;
   if(ptr == max)
      ptr = 0;
}

string handle_history(string str)
{
   int tmp;
   string *tmpq;
   string *lines;
   string cmd;

   if(str[0] != '!' || str == "!")
   {
      enqueue(str);
      return str;
   }

   if(!history_queue || sizeof(history_queue) == 1)
   {
      write(str[1 .. strlen(str) - 1]+": Event not found.\n");
      return "";
   }
   if(str == "!!")
   {
      if((tmp = ptr - 1) < 0)
         tmp = max - 1;
      cmd = history_queue[tmp];
   }
   else
   if(sscanf(str,"!%d",tmp))
   {
      if(tmp > 0)
         tmp -= cmd_num;
      if(tmp >= 0 || (-tmp) >= max)
      {
         write(tmp+": Event not found.\n");
         return "";
      }
      if((tmp = ptr + tmp) < 0)
         tmp = max + tmp;
      cmd = history_queue[tmp];
   }
   else
   {
      str = str[1..strlen(str)];
      if(!ptr)
         tmpq = history_queue;
      else
         tmpq = history_queue[ptr .. (max - 1)] +
            history_queue[0 .. ptr - 1];

      lines = regexp(tmpq,"^"+str);
      if(!sizeof(lines))
      {
         write(str+": Event not found.\n");
         return "";
      }
      cmd = lines[sizeof(lines) - 1];
   }

   write(cmd+"\n");
   enqueue(cmd);
   return cmd;
}
