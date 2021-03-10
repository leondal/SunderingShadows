#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("rose");
  set_id( ({"rose", "flower"}) );
  set_short("A Lovely %^RED%^%^BOLD%^Red Rose%^RESET%^");
  set_long("%^RED%^%^BOLD%^\n"+
    "               .     .                 \n"+
    "          ...  :``   ':                \n"+    
    "           : ```` '    :''::'          \n"+    
    "         ..:..   '     .'' :           \n"+    
    "       ``.    `:     .'     :          \n"+     
    "          :    :    :        :         \n"+    
    "           :   :    :         :        \n"+    
    "           :    :    :        :        \n"+    
    "           :     :    :%^GREEN%^..''''``::. \n"+    
    " %^RED%^          :%^GREEN%^  ...:..'      .'' \n"+   
    "            .'    .'   .::::'          \n"+   
    "           :..'''``:::::::             \n"+   
    "          '          `::::             \n"+   
    "                       `::.            \n"+   
    "                        `::            \n"+   
    "                         :::.          \n"+   
    "             ..:```.:'`.  ::'`.        \n"+   
    "           ..'      `:.:  ::           \n"+   
    "          .:        .:``::::           \n"+   
    "          .:    ..''      :::          \n"+   
    "           : .''           ::          \n"+   
    "            :               :          \n"+   
    "                                %^RESET%^ ");
  set_weight(1);
  set("value", 1);
}
