#include <std.h>
inherit OBJECT;


void create(){
   ::create();
   set_name("%^BOLD%^%^WHITE%^A helpful sign%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This is a simple white sign that sets upon a solid four by four post.  There is some writing upon it if you wish to read it.%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^A helpful sign%^RESET%^");
   set_id(({"sign","helpful sign"}));
   set_weight(10000);
   set("read",(:"sign_read":));
}
int sign_read(string str){
   if(id(str)){
      TP->more(TO->query_property("file"));
      return 1;   
   }
   return 0;
}
void set_file(string g){
   TO->set_property("file", g);
   return;
}