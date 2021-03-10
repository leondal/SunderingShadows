#include <std.h>
#include "/realms/grendel/grendel.h"
#define cap capitalize
inherit DAEMON;

int cmd_newrp(){
    string *classes;
    string theclass, level;
    object *usrs;
    object choice;
    int i;
    usrs = users();
    choice = usrs[random(sizeof(usrs))];
    while(avatarp(choice)) choice = usrs[random(sizeof(usrs))];
    tell_object(TP,"Name:  "+cap(choice->query_name()));
    tell_object(TP,"Race:  "+cap(choice->query_race()));
    tell_object(TP,"Alignment:  "+align_abbrev((int)choice->query_alignment()));

    classes = choice->query_classes();
    
    if(sizeof(classes) == 1) {
       tell_object(TP,"Class: "+cap(classes[0])+ ": " +choice->query_class_level(classes[0]));
    }

    if(sizeof(classes) > 1) {
       for(i = 0;i < sizeof(classes);i++) {
         if(!theclass) {
           theclass = cap(classes[i]) + ": "+ choice->query_class_level(classes[i]);
           continue;
         }
           theclass += " " +cap(classes[i])+": "+choice->query_class_level(classes[i]);
        }
       tell_object(TP,"Class : " +theclass);
    }

    if(choice->query_diety()) {
      tell_object(TP,"Diety: "+cap(choice->query_diety()));
    }
    tell_object(TP,"You may also want to check into things such as "+
    "background and read up on notes.");
    return 1;
}

int help(){
    write("This command will tell you the name of a randomly "+
    "chosen online player and there basic statics - such as race, "+
    "alignment, level, class, and diety if they follow one.  "+
    "It is intended as a means for you to quickly get basic "+
    "access to a characters stats for more effective/easier "+
    "brainstorming for quests.");
    return 1;
}
