//armor.c

#include <std.h>
#define TAB "    "

inherit ARMOUR;

void set_owner(string who);

string uwear,wwear,uuwear,wuwear,ustrike,wstrike,rejectm;

void create(){
   ::create();
   set_id(({"armor"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   set_struck((:TO,"strikeme":));
}

int is_avatar_item(){
   return 1;
}

void set_owner(string who){
   set("owner",who);
}

int wearme(){
    string tmp;
   if(query("owner") && (ETO->query_name() != query("owner"))){
      if(rejectm) tell_object(ETO,rejectm);
      remove();
      return 0;
   }
   tell_object(ETO,uwear);
    tmp = replace_string(wwear, "USER", ETO->query_cap_name());
    tell_room(environment(ETO),tmp,ETO);
   return 1;
}

int unwearme(){
    string tmp;
   tell_object(ETO,uuwear);
    tmp = replace_string(wuwear, "USER", ETO->query_cap_name());
    tell_room(environment(ETO),tmp,ETO);
   return 1;
}

int strikeme(){
    string tmp;
   tell_object(ETO,ustrike);
    tmp = replace_string(wstrike, "USER", ETO->query_cap_name());
    tell_room(environment(query_worn()),tmp,ETO);
   return 0;
}

void set_ustrike(string str){
   ustrike = str;
}

void set_wstrike(string str){
   wstrike = str;
}
void set_uwear(string str){
   uwear = str;
}
void set_wwear(string str){
   wwear = str;
}

void set_uunwear(string str){
   uuwear = str;
}
void set_wunwear(string str){
   wuwear = str;
}
void set_rejectm(string str){
   rejectm = str;
}

int weight;
int save_me(string file){
     weight = query_weight();
     return ::save_me(file);
}

int restore_me(string file){
    ::restore_me(file);
    set_weight(weight);
}

int save_as_file(string file){
   string theText;
   string tmp,*tmps;
   int i;

   theText = "//file \n\n#include <std.h>\n\ninherit ARMOUR;\n\nvoid create(){\n"+TAB+"::create();\n";
   theText += ""+TAB+"set_name(\""+query_name()+"\");\n";
   tmps = query_id();
   tmp = "";
   for (i = 0;i<sizeof(tmps);i++) {
      tmp += "\""+tmps[i]+"\",";
   }
   theText += ""+TAB+"set_id(({"+tmp+"}));\n";
   theText += ""+TAB+"set_short(\""+query_short()+"\");\n";
   tmp = query("long");
   tmp = tmp[0..strlen(tmp)-2];
   theText += ""+TAB+"set_long(\n@ARMOR\n"+tmp+"\nARMOR\n"+TAB+""+TAB+");\n";

   theText += ""+TAB+"set_weight("+query_weight()+");\n";
   theText += ""+TAB+"set_size("+query_size()+");\n";
   theText += ""+TAB+"set_type(\""+query_type()+"\");\n";
   tmps = query_limbs();
   tmp = "";
   for (i = 0;i<sizeof(tmps);i++) {
      tmp += "\""+tmps[i]+"\",";
   }
   theText += ""+TAB+"set_limbs(({"+tmp+"}));\n";
   theText += ""+TAB+"set_ac("+query_ac()+");\n";
   theText += ""+TAB+"set_property(\"enchantment\","+query_property("enchantment")+");\n";
   theText += ""+TAB+"set_value("+query_value()+");\n";
   theText += "}";
  
   write_file(file,theText);
}
