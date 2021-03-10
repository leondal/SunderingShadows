//_mystyle.c
//coded by Circe with the new fighting styles

#include <std.h>
#include <daemons.h>

inherit DAEMON;
string *styles = ({ "peasant","swashbuckler","thug","soldier","dervish" });

int help(){
    write(
@CIRCE
This command will allow you to see your fighting style.
The first time you use it, if you have no fighting style 
selected, you will be prompted to choose one.
CIRCE
        );
if(avatarp(TP)){
   write(
@MORE
Immortals may change their styles whenever they wish by 
typing mystyle and the style name <mystyle peasant>.
MORE
   );
}
}

int cmd_mystyle(string str){
    if (!str) {
       if(!TP->query_fighter_style()){
          tell_object(TP,"Please choose a fighting style.  "+
             "You may choose peasant, swashbuckler, thug, "+
             "soldier, or dervish.  Syntax <mystyle stylename>.");
       return 1;
       }else{
          write("Your fighting style is "+TP->query_fighter_style()+".");
          return 1;
       } 
    }
    if(!TP->query_fighter_style() || avatarp(TP)){
       str = lower_case(str);
       if(member_array(str,styles) == -1){
          write("%^RED%^Sorry, that is not a style you can choose.");
          write("%^RESET%^%^BOLD%^Please pick a style from the list:");
          return 1;
       }
       TP->set_fighter_style(str);
       write("Your fighting style is now "+str+"!");
       return 1;
    }else{
       write("You already have a fighting style!  <mystyle> will "+
          "show you what it is.");
    return 1;
    }
}