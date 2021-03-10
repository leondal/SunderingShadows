//weapon.c

#include <std.h>
#define TAB "    "

inherit WEAPON;

string uwield, wwield;
string uuwield, wuwield;
string uhit, whit;

void create(){
   ::create();
   set_id(({"weapon"}));
   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
}

int hitme(){
    string temp;

    if(uhit != "")
    tell_object(ETO,uhit);
    if(whit != ""){
      temp = replace_string(whit, "USER", ETO->query_cap_name());
      tell_room(environment(query_wielded()),temp,ETO);
    }
   return 0;


}

int wieldme(){
    string tmp;
   tell_object(ETO,uwield);
    tmp = replace_string(wwield, "USER", ETO->query_cap_name());
    tell_room(environment(ETO),tmp,ETO);
   return 1;


}
int unwieldme(){
    string tmp;
   tell_object(ETO,uuwield);
    tmp = replace_string(wuwield, "USER", ETO->query_cap_name());
    tell_room(environment(ETO),tmp,ETO);
   return 1;


}

int is_avatar_item(){
   return 1;
}

void set_uhit(string str){
   uhit = str;
}


void set_whit(string str){
   whit = str;
}
void set_uwield(string str){
   uwield = str;
}
void set_wwield(string str){
   wwield = str;
}

void set_uunwield(string str){
   uuwield = str;
}
void set_wunwield(string str){
   wuwield = str;
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

   theText = "//file \n\n#include <std.h>\n\ninherit WEAPON;\n\nvoid create(){\n"+TAB+"::create();\n";
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
   theText += ""+TAB+"set_long(\n@WEAPON\n"+tmp+"\nWEAPON\n"+TAB+""+TAB+");\n";

   theText += ""+TAB+"set_weight("+query_weight()+");\n";
   theText += ""+TAB+"set_size("+query_size()+");\n";
   theText += ""+TAB+"set_type(\""+query_type()+"\");\n";
   theText += ""+TAB+"set_prof_type(\""+query_prof_type()+"\");\n";
   theText += ""+TAB+"set_ac("+query_ac()+");\n";
   theText += ""+TAB+"set_property(\"enchantment\","+query_property("enchantment")+");\n";
   theText += ""+TAB+"set_value("+query_value()+");\n";
   theText += ""+TAB+"set_wc(1,"+query_wc()+");\n";
   theText += ""+TAB+"set_large_wc(1,"+query_large_wc()+");\n";

   theText += "}";
  
   write_file(file,theText);
}
