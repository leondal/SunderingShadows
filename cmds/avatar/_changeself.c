//

#include <std.h>
#include <daemons.h>

inherit DAEMON;

string *persona_classes=({});

int cmd_changeself(string str) {

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

   if(!str) {
      return notify_fail("Please specify your name.\n");
   }

   if(user_exists(str) && str != (string)TPQN) {
      return notify_fail("I'm sorry that player already exists.\n");
   }
   tell_object(TP,"%^BOLD%^You are changing your name to "+str);

//   TP->set_disguised(1);
//   Was breaking first-time avatar logins with the persona.
   TP->set_vis_name(str);
   TP->set_id(({str}));


   tell_object(TP,"Please enter your title or short");
   input_to("short");
   return 1;
}

void short(string str) {
   if(!str) {
      tell_object(TP,"Please enter your title or short");
      input_to("short");
      return 1;
   }
   if(str == "**") {
      tell_object(TP,"Persona Set.");
      return;
   }
   tell_object(TP,"You short is set to.."+str);
   TP->set_disguise(str);
   tell_object(TP,"Please Input, your race..");
   input_to("race");
}

void race(string str) {
   string *races = RACE_D->query_races();
   races = races - ({"blah","elven-dragon","pegataur","alaghi","unborn"});
   if(str == "**") {
      tell_object(TP,"Persona Set.");
      return;
   }
   if(member_array(str, races) == -1) {
      tell_object(TP,"That race is not allowed, please input a new race.");
      input_to("race");
      return;
   }
   TP->set_race(str);

   tell_object(TP,"Your race is set to.."+str);
   tell_object(TP,"Please input your gender");
   input_to("gender");
}

void gender(string str) {
   if(str == "**") {
      tell_object(TP,"Persona Set.");
      return;
   }
   if(str != "male" && str != "female" && str != "eunich") {
      tell_object(TP,"male female or eunich");
      input_to("gender");
      return 1;
   }
   TP->set_gender(str);

   tell_object(TP,"Your gender is set to.."+str);
   tell_object(TP,"Please input your max hit points");
   input_to("hp");

}

void hp(string str) {
   int hit;
   if(!str) {

      tell_object(TP,"Please input your max hit points");
      input_to("hp");
      return 1;
   }
   if(str == "**") {
      tell_object(TP,"Persona Set.");
      return;
   }
   if(sscanf(str,"%d",hit)!=1) {

      tell_object(TP,"Please input your max hit points");
      input_to("hp");
      return 1;

   }
   TP->set_max_hp(hit);

   tell_object(TP,"Your hit points are set to.."+hit);
   tell_object(TP,"Please input your strength");
   input_to("strength");
}


void strength(string str) {
   int hit;
   if(!str) {

      tell_object(TP,"Please input your strength");
      input_to("strength");
      return 1;
   }
   if(str == "**") {
      tell_object(TP,"Persona Set.");
      return;
   }
   if(sscanf(str,"%d",hit)!=1) {

      tell_object(TP,"Please input your stength");
      input_to("strength");
      return 1;

   }
   TP->set_stats("strength",hit);

   tell_object(TP,"Your strength is set to.."+hit);
   tell_object(TP,"Please input your intelligence");
   input_to("intelligence");
}
void intelligence(string str) {
   int hit;
   if(!str) {

      tell_object(TP,"Please input your intelligence");
      input_to("intelligence");
      return 1;
   }
   if(str == "**") {
      tell_object(TP,"Persona Set.");
      return;
   }
   if(sscanf(str,"%d",hit)!=1) {

      tell_object(TP,"Please input your intelligence");
      input_to("intelligence");
      return 1;

   }
   TP->set_stats("intelligence",hit);

   tell_object(TP,"Your intelligence is set to.."+hit);
   tell_object(TP,"Please input your dexterity");
   input_to("dexterity");
}
void dexterity(string str) {
   int hit;
   if(!str) {

      tell_object(TP,"Please input your dexterity");
      input_to("dexterity");
      return 1;
   }
   if(str == "**") {
      tell_object(TP,"Persona Set.");
      return;
   }
   if(sscanf(str,"%d",hit)!=1) {

      tell_object(TP,"Please input your dexterity");
      input_to("dexterity");
      return 1;

   }
   TP->set_stats("dexterity",hit);

   tell_object(TP,"Your dexterity is set to.."+hit);
   tell_object(TP,"Please input your constitution");
   input_to("constitution");
}
void constitution(string str) {
   int hit;
   if(!str) {

      tell_object(TP,"Please input your constitution");
      input_to("constitution");
      return 1;
   }
   if(str == "**") {
      tell_object(TP,"Persona Set.");
      return;
   }
   if(sscanf(str,"%d",hit)!=1) {

      tell_object(TP,"Please input your constitution");
      input_to("hp");
      return 1;

   }
   TP->set_stats("constitution",hit);
   tell_object(TP,"Your constitution is set to.."+hit);
   tell_object(TP,"Please input your wisdom");
   input_to("wisdom");
}
void wisdom(string str) {
   int hit;
   if(!str) {

      tell_object(TP,"Please input your wisdom");
      input_to("wisdom");
      return 1;
   }
   if(str == "**") {
      tell_object(TP,"Persona Set.");
      return;
   }
   if(sscanf(str,"%d",hit)!=1) {

      tell_object(TP,"Please input your wisdom");
      input_to("wisdom");
      return 1;

   }
   TP->set_stats("wisdom",hit);

   tell_object(TP,"Your wisdom set to.."+hit);
   tell_object(TP,"Please input your charisma");
   input_to("charisma");
}
void charisma(string str) {
   int hit;
   if(!str) {

      tell_object(TP,"Please input your charisma");
      input_to("charisma");
      return 1;
   }
   if(str == "**") {
      tell_object(TP,"Persona Set.");
      return;
   }
   if(sscanf(str,"%d",hit)!=1) {

      tell_object(TP,"Please input your charisma");
      input_to("charisma");
      return 1;

   }
   TP->set_stats("charisma",hit);

   tell_object(TP,"Your charisma is set to.."+hit);
   tell_object(TP,"Please input your first class and level(under 50 if not for avatar) (class,level)");
   input_to("class1");
}

void fix_classes(object obj)
{
    int i;
    string *classes=({});
    if(!objectp(obj)) { return; }
    if(!sizeof(persona_classes)) { persona_classes += ({ (string)obj->query_class() }); }
    classes = keys(obj->query_levels());
    for(i=0;i<sizeof(classes);i++)
    {
        if(member_array(classes[i],persona_classes) != -1) { continue; }
        obj->set_class(classes[i]);
        obj->set_mlevel(classes[i],0);
        obj->remove_class(classes[i]);
    }
    return;
}

void class1(string str) {
   int level, i,j;
   string theclass, classes;

   if(!str) {
      tell_object(TP,"Please input your first class and level(under 50 if not for avatar) (class,level)");
      input_to("class1");
   }

   if(str == "**") {
      fix_classes(TP);
      tell_object(TP,"Persona Set.");
      return;
   }
   if(sscanf(str,"%s,%d",theclass, level) != 2) {
      tell_object(TP,"Please input your first class and level (under 50 if not for avatar) (class,level)");
      input_to("class1");
      return;
   }
   if(level > 50 && TP->query_vis_name() != TP->query_name()) {
      tell_object(TP,"Please input your first class and level (under 50 if not for avatar) (class,level)");
      input_to("class1");

      return;
   }
   classes = TP->query_classes();
   j = sizeof(classes);
   for(i=0;i<j;i++) {
      TP->remove_class(classes[i]);
   }

   TP->set_class(theclass);
   TP->set_mlevel(theclass,level);
   TP->set_guild_level(theclass,level);
   if(theclass == "ranger" || theclass == "paladin" || theclass == "antipaladin") {
      TP->set_guild_level("cleric",level-7);
   }

   persona_classes += ({ theclass });
   TP->set_posed(theclass);   
   fix_classes(TP);


   tell_object(TP,"You class is set to "+theclass+" at level "+level+".");
   tell_object(TP,"Please input your second class and level (class,level) or ** to exit.");
   input_to("class2");
}

void class2(string str) {
   int level, i,j;
   string theclass, classes;

   if(!str) {
      tell_object(TP,"Please input your second class and level (class,level)");
      input_to("class2");
   }

   if(str == "**") {
      fix_classes(TP);
      tell_object(TP,"Persona Set.");
      return;
   }
   if(sscanf(str,"%s,%d",theclass, level) != 2) {
      tell_object(TP,"Please input your second class and level (class,level)");
      input_to("class2");
      
      return;
   }

   if(level > 50 && TP->query_vis_name() != TP->query_name()) {
      tell_object(TP,"Please input your first class and level (under 50 if not for avatar) (class,level)");
      input_to("class1");
      return;
   }
   TP->set_class(theclass);
   TP->set_mlevel(theclass,level);

   TP->set_guild_level(theclass,level);
   if(theclass == "ranger" || theclass == "paladin" || theclass == "antipaladin") {
      TP->set_guild_level("cleric",level-7);
   }

   persona_classes += ({ theclass });
   TP->set_posed(theclass);  
   fix_classes(TP);

   tell_object(TP,"You class is set to "+theclass+" at level "+level+".");
   tell_object(TP,"Please input your third class and level (class,level) or ** to exit.");
   input_to("class3");
}

void class3(string str) {
   int level, i,j;
   string theclass, classes;

   if(!str) {
      tell_object(TP,"Please input your third class and level (class,level)");
      input_to("class3");
   }

   if(str == "**") {
      fix_classes(TP);
      tell_object(TP,"Persona Set.");
      return;
   }
   if(sscanf(str,"%s,%d",theclass, level) != 2) {
      tell_object(TP,"Please input your third class and level (class,level) or ** to exit.");
      input_to("class3");
      return;
   }

   if(level > 50 && TP->query_vis_name() != TP->query_name()) {
      tell_object(TP,"Please input your first class and level (under 50 if not for avatar) (class,level)");
      input_to("class3");
      return;

   }
   
   TP->set_class(theclass);
   TP->set_mlevel(theclass,level);

   TP->set_guild_level(theclass,level);
   if(theclass == "ranger" || theclass == "paladin" || theclass == "antipaladin") {
      TP->set_guild_level("cleric",level-7);
   }

   persona_classes += ({ theclass });
   TP->set_posed(theclass);  
   fix_classes(TP);

   tell_object(TP,"You class is set to "+theclass+" at level "+level+".");
   tell_object(TP,"Persona set.");
}

int help() {
   write(
        "Syntax: changeself <name>\n\n"
        +"  The basic command for altering your appearance.  Use it with the name you want to use and follow the instructions as you get to them.  At the end, if you only want one class type ** after you have entered 1 class.  Do not just press enter or you could have errors."
        );
   return 1;
}
