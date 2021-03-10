#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This house is more like a shrine than anything else. There is a"+
   " large altar that dominates the center of the southern wall. There"+
   " is a large green silk cushion in front of the altar that can"+
   " be used to pray or meditate on. In the center of the wall is a"+
   " large oak tree that has been created from copper. The hues of the"+
   " copper are beautiful, the leaves are a swirled green and the"+
   " trunk is a deep brown. The rest of the room is decorated with"+
   " large swathes of pale green silk and a few oil paintings of"+
   " the city of Aketon.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   "door" : "There is a door to the southeast that is made out of solid"+
   " oak. Carved into the wood is a large and detailed tree.",
   ({"altar","shrine"}) : "The altar is obviously dedicated to the"+
   " god Silvanus, with the large oak tree that is his symbol dominating"+
   " the center of the wall.",
   ({"tree","oak tree","copper tree"}) : "The copper oak tree has been"+
   " beautifully wrought from careful metal work. The leaves are the"+
   " natural minty green of copper, while the trunk is a dark brown."+
   " You almost expect the leaves and branches to sway in the wind.",
   ({"cushion","silk cushion","green cushion","green silk cushion"}) : "%^GREEN%^In"+
   " front of the altar is a large green silk cushion that can be"+
   " knelt upon for prayer or meditation. It looks fairly comfortable.",
   ({"silk","green silk"}) : "%^GREEN%^%^BOLD%^Swathes of pale green"+
   " silk are hung artfully about the room, giving this place an"+
   " almost sequestered feeling.",
   "paintings" : "There are several paintings hung around the room that"+
   " show Aketon from various angles during the different seasons. The"+
   " massive trees never seem to lose their leaves, but sometimes they"+
   " take on the reddish hues of fall. There appear to be five main"+
   " trees of the city of Aketon.",
   ]));
   set_door("door",RPATH3+"3one36","northwest",0);
   set_exits( (["northwest":RPATH3+"3one36"]) );
}
