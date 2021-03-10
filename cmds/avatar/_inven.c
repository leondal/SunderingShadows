// _inven.c simplified and improved version of scan for avatar use
// added to show enchantments, AC, and dir origin - Styx 4/21/02

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int tab, *place, flag;
string ret;

void printaallin(object ob, int num);
void printascan(object ob, int num);

int cmd_inven(string str){
   object obj;
   string junk, heading;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

   if(!str || str == "") {
        str = TP->query_name();
   }
   if(sscanf(str,"-l %s",junk) == 1){
      flag = 1;
      obj = find_player(junk);
   }
   else{
      flag = 0;
      obj = find_player(str);
   }
   if(!obj) return notify_fail("Failed to find that player.\n");
   if(wizardp(obj) && obj->query_level() > TP->query_level()) return 0;
   heading = "%^BOLD%^      Short id - - - - - - %^BLUE%^WorN/%^RED%^WielD/"
       "%^RESET%^qty-%^BOLD%^%^WHITE%^ench-%^MAGENTA%^AC%^RESET%^-"
       "%^YELLOW%^value-%^RESET%^from dir\n";
   if(flag) ret = "Inventory of "+junk+":\n"+heading;
   else ret = "Inventory of "+capitalize(str)+":\n"+heading;
   place = allocate(5);
   printaallin(obj,0);
//   write(ret);
   TP->more(explode(ret,"\n"));
   return 1;
}

void printaallin(object ob, int num){
   int i;
   mixed *inv;
   tab += 2;
   inv = all_inventory(ob);
   place[num] = 0;
   for(i=0;i<sizeof(inv);i++){
      printascan(inv[i], num);
      if(flag) printaallin(inv[i], num + 1);
   }
   tab -= 2;
}

void printascan(object ob, int num){
   int cnt, i, ench, ac, space, vials, value;
   string dir, st, short, tmp;
   if(!ob){ ret += "No object.\n"; return; }
   short = ob->query("short");
   space = 1;
   if (!short)  short = "(Invisible Object)";
   if (!stringp(short)) short = "(Invisible Object)";

   //while (sscanf(short, "%*s%%^%s%%^%*s", tmp) > 2)
   short = FILTERS_D->filter_colors(short);
   
   if (strlen(short) > 31)
      short = short[0..27] + "~  ";
      else
         for (i = strlen(short); i < 31; i++)
           short = short + " ";
   if(ob->query_worn()) {
       short = short + "%^BOLD%^%^BLUE%^ WN  %^RESET%^";
       space = 0;
   }
   if(ob->query_wielded()) {
       short = short + "%^BOLD%^%^RED%^ WD  %^RESET%^";
       space = 0;
   }
   if( ((string) ob->query_name() == "blue vial") || ((string)ob->query_name() == "holy water") ) {
       vials = ob->query_uses();
       if(vials < 10) {
         short = short +"  "+vials+"  ";
         space = 0;
       }  else { 
       short = short +" "+vials+"  ";
       space = 0;
       }
   }
   if(space)  short = short + "     ";

   ench = ob->query_property("enchantment");
   ac = ob->query_ac();
   value = ob->query_value();
   switch(value) {
     case 0..9          : value = "     "+value;     break;
     case 10..99        : value = "    "+value;      break;
     case 100..999      : value = "   "+value;       break;
     case 1000..9999    : value = "  "+value;        break;
     case 10000..99999  : value = " "+value;         break;
     default            : value = ""+value;          break;
   }  
   if(!ench && !ac)  st = short+" -  -  %^YELLOW%^"+value+"%^RESET%^ ";
     else st = short+"%^BOLD%^ "+ench+", %^MAGENTA%^"
       +ac+"  %^YELLOW%^"+value+"%^RESET%^ ";
// was euid but changes were making that come back Restore most of the time *Styx* 12/02
   dir = getuid(ob);
   st = st+"("+dir+")";
   if(st && st != ""){
      place[num] += 1;
      while(cnt < tab){ ret += " "; cnt += 1; }
      ret += place[num];
      if(place[num] < 10) ret += ":  ";
      else ret += ": ";
      ret += capitalize(st) + "\n";
   }
}

void help(){
   write("Syntax: inven [-l] [player]\n"+
      "This command lists the inventory of a player.\n"+
      "Example: inven -l obsidian\n"
      "Note:  The -l is optional and will show items in sacks also.\n"
      "It will show the true short of the item rather than the obvious.\n"
      "Also now shows # enchantments and total AC benefit. (Styx 5/02)\n"
      "Added column headings & value. (Styx 6/02)\n");
}
