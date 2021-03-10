

#include <std.h>

int stringInSet(string str, string *set){
   
   int i;
   for (i=0;i<sizeof(set);i++) {
      if (strsrch(str,set[i]) ){
         return 1;
      }
   }
   return 0;
}
