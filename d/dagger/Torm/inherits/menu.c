#include <std.h>
inherit VAULT;
void create(){
  ::create();
}
void init(){
  ::init();
  add_action("read","read_menu");
  }
int read_menu(string str){
  object ob;
  string *menu_item,amidon;
  int length;
  if(str!="menu") return 0;
  ob=present("waitstaff");
  if(!ob){
  write("You cannot read the menu, as it is splattered with blood.");
  return 1;
  }
  menu_item=ob->query_menu();
  length=sizeof(menu_item);
  message("Ninfor","%^MAGENTA%^This is a list of the drinks sold at this establishment.\n",this_player());
 message("Ninfo",
"%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n",this_player());
  while(length--){
  amidon=sprintf("      %GREEN% %-20s  %YELLOW%%2d %RESET%%WHITE% silver pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
  write(amidon);
  }
  message("Ninfo",
"%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n",this_player());
  message("Ninfo","<buy name> gets you the menu item.\n",this_player());
  return 1;
}
