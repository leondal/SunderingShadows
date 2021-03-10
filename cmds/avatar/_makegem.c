//Avatar command to generate attuned gems by ~Circe~ 3/23/16
//Requested by Brandobaris 
#include <std.h>
#include <daemons.h>

inherit DAEMON;

int help();

string gemspell,gemshort,gemobv,gemlong,gemid,*gemids;
int gemlvl;
object mygem;

void make_gem(int x);

#define NAMES ({"jasper","turquoise","azurite","black quartz","white quartz","citrine","hematite","amethyst","green tourmaline","aquamarine","beryl","orange agate","topaz","moonstone","garnet","snowflake obsidian","onyx","emerald","ruby","sapphire","diamond","blue diamond"})

#define GEM ({"%^RED%^jasper","%^CYAN%^tur%^BOLD%^qu%^RESET%^%^CYAN%^oise","%^BOLD%^%^CYAN%^azurite","%^BOLD%^%^BLACK%^black quartz","%^BOLD%^white quartz","%^YELLOW%^citrine","%^BOLD%^%^BLACK%^hematite","%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t","%^GREEN%^green tourmaline","%^CYAN%^aquamarine","%^GREEN%^be%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^yl","%^ORANGE%^orange agate","%^YELLOW%^topaz","%^BOLD%^moonstone","%^RED%^garnet","%^BOLD%^%^WHITE%^sno%^BLACK%^w%^WHITE%^flake %^BLACK%^obs%^WHITE%^i%^BLACK%^dian","%^BOLD%^%^BLACK%^onyx","%^BOLD%^%^GREEN%^emerald","%^BOLD%^%^RED%^ruby","%^BOLD%^%^BLUE%^sapphire","%^BOLD%^dia%^CYAN%^m%^WHITE%^ond","%^BOLD%^%^BLUE%^blue dia%^CYAN%^m%^BLUE%^ond"})

int cmd_makegem(string str){
   int lvl;
   string myspell,spell,testspell;
   if (!str) {
      help();
      return 1;
   }
   if(sscanf(str,"%d %s",lvl,myspell) == 2) {
      if(lvl < 1 || lvl > 50){
         tell_object(TP,"%^RED%^ERROR%^RESET%^: Please select a level between 1 and 50.");
         return 1;
      }
      myspell = lower_case(myspell);
      spell = replace_string(myspell," ","_");
      spell = "/cmds/spells/"+spell[0..0]+"/_"+spell;
      if(!file_exists(spell+".c")) {
         tell_object(TP,"That power does not exist.");
         return 1;
      }
      testspell = new(spell+".c");
      if(!testspell->query_spell_level("psion")){
         tell_object(TP,"That is not a valid psion power!");
         return 1;
      }
      gemspell = myspell;
      gemlvl = lvl;
      gemids = ({});
      tell_object(TP,"You will create one or more attuned gems with the "
         "following properties:\nPower: "+myspell+", Level: "+lvl+".\nPlease "
         "enter the short description for your gem. Leave blank for a "
         "default description. Enter ** to quit.");
      input_to("gem_short");
      return 1;
   }else{
      tell_object(TP,"Syntax: makegem <level> <power>.");
      return 1;
   }
}

void gem_short(string str){
   int j;
   string gemtype;
   if(!str || str == "") {
      j = random(sizeof(NAMES));
      gemtype = NAMES[j];
      gemids += ({gemtype});
      gemtype = GEM[j];
      gemshort = "%^RESET%^%^MAGENTA%^a flawless %^RESET%^"+gemtype+" %^RESET%^%^BOLD%^%^YELLOW%^(glowing softly)%^RESET%^";
      gemlong = "This is a polished piece of "+gemtype+"%^RESET%^.  It sparkles "+
      "prettily in the light, and it would probably fetch a good price. %^YELLOW%^(glowing softly)%^RESET%^";
      tell_object(TP,"Your gem will have the following descriptions:\n"
         "Short: "+gemshort+"\nLong: "+gemlong+".");
      tell_object(TP,"Please enter the number of gems you'd like to create.");
      input_to("amount");
      return;
   }

   if(str == "**"){
      tell_object(TP,"You have stopped the makegem process.");
      return;
   }
   input_to("check_short",str);
   write("The identified short of this object is "+str+".  Is this correct, yes or no?");
   write("Type ** to quit.");
   return;
}

void check_short(string str,string short) {
   if(str == "**"){
      tell_object(TP,"You have stopped the makegem process.");
      return;
   }
   if(str == "yes" || str == "y") {
      gemshort = short;
      write("Please input the obvious short for this item. This is the short that one would generally classify as.");
      write("For Example: the short might be \"Queens medallion\", the obvious short would be \"small medallion\"");
      write("NOTE: a blank line will simply use the short description by default.");
      write("Type ** to quit.");
      input_to("obv_short");
      return 1;
   }
   write("Please input the short description for this gem.");
   write("Type ** to quit.");
   input_to("gem_short");
   return;
}

void obv_short(string str){
   if(str == "**"){
      tell_object(TP,"You have stopped the makegem process.");
      return;
   }
   if(str && str != "") {
       write("The obvious short for this object is: "+str+".\n Is this correct, yes or no?");
       write("Type ** to quit.");
       input_to("check_obv_short",str);
       return 1;
   }
   gemobv = gemshort;
   write("Please input the long description.\n%^RED%^Note:%^RESET%^ Use ** to end the long description. Don't quit in this field.");
   input_to("long", "");
}

void check_obv_short(string str, string obv_short) {
   if(str == "**"){
      tell_object(TP,"You have stopped the makegem process.");
      return;
   }
   if(str == "yes" || str == "y") {
      gemobv = obv_short;
      write("Please input the long description.\n%^RED%^Note:%^RESET%^ Use ** to end the long description. Don't quit in this field.");
      input_to("long", "");
      return 1;
   }
   write("Please input the obvious short for this item. This is the short that one would generally classify as.");
   write("For Example: the short might be \"Queens medallion\", the obvious short would be \"small medallion\"");
   write("NOTE: a blank line will simply use the short description by default.");
   write("Type ** to quit.");
   input_to("obv_short");
   return 1;
}

void long(string str, string longd) {
   if(!str) {
      write("Please input the long description.\n%^RED%^Note:%^RESET%^ Use ** to end the long description. Don't quit in this field.");
      input_to("long",longd);
      return;
   }
   if(str != "**") {
      longd += str + "\n";
      input_to("long",longd);
      return;
   }
   write(longd+"\nIs this the correct long description?  yes or no?");
   write("Type ** to quit.");
   input_to("check_long",longd);
   return ;
}

void check_long(string str, string longd) {
   if(str == "**"){
      tell_object(TP,"You have stopped the makegem process.");
      return;
   }
   if(str == "yes" || str == "y") {
      gemlong = longd;
      tell_object(TP,"Please enter any ids you would like to add.");
      tell_object(TP,"Commas deliminate multiple ids <ruby,blazing gem,blazing ruby>.");
      write("Type ** to quit.");
      input_to("ids");
      return;
   }
   write("Please input the long description.\n%^RED%^Note:%^RESET%^ Use ** to end the long description. Don't quit in this field.");
   input_to("long", "");   
   return;
}

void ids(string str){
   gemids += ({"gem","attuned gem"});
   if(str == "**"){
      tell_object(TP,"You have stopped the makegem process.");
      return;
   }
   if(!str){
      tell_object(TP,"Your gem will have the following ids: "+identify(gemids)+".");
      tell_object(TP,"Please enter the number of gems you'd like to create.");
      tell_object(TP,"Type ** to quit.");
      input_to("amount");
      return;
   }
   gemids += explode(str,",");
   tell_object(TP,"The ids for this gem will be: "+identify(gemids)+". Is this correct? yes or no?");
   write("Type ** to quit.");
   input_to("check_ids",str);
   return;
}

void check_ids(string str, string *ids) {
   if(str == "**"){
      tell_object(TP,"You have stopped the makegem process.");
      return;
   }
    if(str == "yes" || str == "y") {
       tell_object(TP,"Please enter the number of gems you'd like to create.");
      tell_object(TP,"Type ** to quit.");
      input_to("amount");
      return;
   }
   tell_object(TP,"Please enter any ids you would like to add.");
   tell_object(TP,"Commas deliminate multiple ids <ruby,blazing gem,blazing ruby>.");
   write("Type ** to quit.");
   input_to("ids");
   return;
}    

void amount(string str) {
   int numgems;
   if(!str) {
      write("You create one gem attuned to "+gemspell+" at level "+gemlvl+".");
      make_gem(1);
      return 1;
   }
   if(str == "**"){
      tell_object(TP,"You have stopped the makegem process.");
      return;
   }
   numgems = atoi(str); //should weed out any strange inputs
   if(numgems < 1) numgems = 1;
   if(numgems > 20) numgems = 20;
   tell_object(TP,"You create "+numgems+" gems attuned to "+gemspell+" at level "+gemlvl+".");
   make_gem(numgems);
   return;
}

void make_gem(int x){
   int i,y;
   for(i=0;i<x;i++){
      mygem = new("/d/magic/obj/attuned_gem");
      mygem->set_power(gemspell);
      mygem->set_level(gemlvl);
      mygem->set_short(gemshort);
      mygem->set_obvious_short(gemobv);
      mygem->set_long(gemlong);
      for(y=0;y<sizeof(gemids);y++){
         mygem->add_id(gemids[y]);
      }
      mygem->move(TP);
   }
   return;
}

int help(){
    write(
@CIRCE
Usage:  makegem <level> <power>

This will make a gem of the <level> and <power> you specify.
Valid levels are 1-50, but please be reasonable. 

%^RED%^Note:%^RESET%^ Generally, make it the same level or a 
few higher than the intended recipient. For comparison, a 
level 40 psion with the proper feats and gear might have a 
caster level around 53.

Through this command, you can determine the attuned gem's:
Short description 
Obvious short
Long description 
Number created

Any of these fields can be left blank.

Like scrolls, these gems are not saved in separate files, 
so if you have a description that you want to use multiple 
times, either create many gems at once or save the text 
in a file on your computer.

CIRCE
    );
    return 1;
} 
