//~Circe~ 11/29/07 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Meditation Room of the Spire of Serenity, Seneca");
   set_short("%^BOLD%^%^WHITE%^Meditation Room of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Meditation Room of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^\n"+
      "%^CYAN%^The gently curved walls of this open room have been painted "+
      "a soft %^BOLD%^%^CYAN%^azure shade%^RESET%^%^CYAN%^, "+
      "setting it apart from the other rooms of the tower.  "+
      "Piled %^BOLD%^%^WHITE%^rugs %^RESET%^%^CYAN%^form a "+
      "cushion over the stone floor, and additional %^MAGENTA%^"+
      "pillows %^CYAN%^in various hues have been strewn across "+
      "the floor.  Five low %^ORANGE%^tables %^CYAN%^with recessed tops "+
      "are placed throughout the room, barely raised off the floor on "+
      "their short legs to allow easy access to those seated on "+
      "the floor.  Each table has an %^RESET%^outline %^CYAN%^drawn "+
      "on its surface and is in the process of becoming a beautiful "+
      "%^BOLD%^%^WHITE%^s%^YELLOW%^a%^RED%^n%^GREEN%^d %^CYAN%^p"+
      "%^BLACK%^a%^MAGENTA%^i%^BLUE%^n%^YELLOW%^t%^RESET%^%^MAGENTA%^"+
      "i%^BOLD%^%^GREEN%^n%^RED%^g %^RESET%^%^CYAN%^that will later "+
      "be swept away.  Psions in Seneca have found that creating "+
      "these exquisite works of art can help focus the mind and "+
      "channel the energy - thus, they value the act of creation "+
      "rather than the creation itself.  A lip surrounds each table "+
      "top, separating it from the small shelves that line the "+
      "table and hold %^RESET%^bowls %^CYAN%^of %^BOLD%^%^WHITE%^"+
      "sand %^RESET%^%^CYAN%^in vibrant %^BOLD%^c%^GREEN%^o%^RED%^"+
      "l%^YELLOW%^o%^BLUE%^r%^RESET%^%^MAGENTA%^s%^CYAN%^.  Arched "+
      "windows without glass are placed high on the walls near the "+
      "ceiling, helping protect the sand paintings in progress.  "+
      "Each may be closed by means of a cleverly designed shutter "+
      "that slides into the wall, a unique innovation.  Hanging within "+
      "each open window is a beautiful %^ORANGE%^metal wind chime "+
      "%^CYAN%^that creates a soft melody to help foster an air "+
      "of relaxation here.%^RESET%^\n");
   set_smell("default","The clean scent of the ocean mingles with a light fragrance of ozone.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"floor","rugs"}) : "The stone floor has been softed by "+
         "piles of rugs in all hues.  The rugs overlap one another "+
         "from many angles, making any one rug's pattern difficult "+
         "to discern.  The topmost layer seems to be rugs "+
         "that are most solid in color, softening the jarring "+
         "effect the pile might otherwise create.  You may <sit> "+
         "or <lie> on the rugs if you like.",
      ({"pillow","pillows"}) : "Large, thin pillows in all %^MAGENTA%^"+
         "v%^BOLD%^a%^RED%^r%^YELLOW%^i%^GREEN%^o%^BLUE%^u%^CYAN%^s "+
         "%^WHITE%^h%^RED%^u%^MAGENTA%^e%^GREEN%^s%^RESET%^ have "+
         "be spread around the room.  Some feature tassels or fringe, "+
         "and you may pull one up to <sit> on if you'd like.",
      ({"table","tables","shelves","bowls"}) : "%^ORANGE%^The tables "+
         "are simple in construction and design, featuring four legs, "+
         "a recessed top, and a lip which separates if from the shelves "+
         "surrounding the table top.  The shelves hold bowls of colored "+
         "sand and the tools needed to produce the sand paintings.",
      ({"tool","tools","chak-pur","funnel"}) : "Simple metal tools "+
         "lie upon the shelves along with the bowls of sand.  They "+
         "seem to come in pairs: one is a metal funnel called a chak-"+
         "pur that has a serrated top, and the second piece is a slender "+
         "metal rod that is run along the top of the chak-pur, causing "+
         "vibrations which gently place the sand.",
      ({"window","windows","arched windows","shutter"}) : "Each of the "+
         "windows is a tall, thin rectangle placed high on the wall.  "+
         "The windows have onion-shaped arches on top, and they are left "+
         "open to the elements.  A cleverly designed shutter that rolls "+
         "back into the wall itself may be pulled out in times of "+
         "inclement weather.",
      ({"chimes","windchimes","chime","wind chime","wind chimes"}) : "Each "+
         "window has a wind chime made of slender metal tubes.  Some have "+
         "crystals hanging among them while others have images of small "+
         "birds.  The chimes produce an airy music that aids in "+
         "relaxation.",
      "paintings" : "The paintings are beautiful!  You should really "+
         "focus on just one painting though.  Judging from the "+
         "tools spread on the shelves, you could also <paint> on one "+
         "if you like.",
      ({"painting","sand painting"}) : ((:TO,"look_painting":))
   ]));
   set_exits(([
      "east" : ROOMS"psi_landing6"
   ]));
   set_door("curtain","/d/attaya/newseneca/rooms/psi_landing6","east",0,"tie");
   set_door_description("curtain","The curtain is soft and cream "+
      "colored, offering only a small amount of privacy to the room beyond.");
   set_lock_description("curtain","tie","This is a simple tie to help hold the curtain closed.");
}

void init(){
   ::init();
   add_action("sit_em","sit");
   add_action("lie_em","lie");
   add_action("paint_em","paint");
}

void look_painting(){
   string mypainting;
   switch(random(5)){
      case 0:  mypainting = "This painting features a series of "+
               "concentric circles outlined in %^YELLOW%^yellow%^RESET%^.  "+
               "Each circle is filled with what seems to be a tightly "+
               "packed series of %^BOLD%^archways %^RESET%^outlined "+
               "in %^BLUE%^d%^GREEN%^a%^MAGENTA%^r%^RED%^k %^ORANGE%^c"+
               "%^CYAN%^o%^BOLD%^%^BLACK%^l%^RESET%^%^GREEN%^o%^BLUE%^r"+
               "%^RED%^s %^RESET%^and banded with progressively "+
               "%^BOLD%^%^BLUE%^l%^RED%^i%^MAGENTA%^g%^GREEN%^h%^YELLOW%^"+
               "t%^CYAN%^e%^WHITE%^r hues %^RESET%^until each center is a "+
               "%^BOLD%^brilliant white%^RESET%^.";
               break;
      case 1:  mypainting = "Awesome in design, this sand painting is "+
               "almost too much for the eye to take in.  It seems to "+
               "use every hue in the %^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^"+
               "a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^"+
               "w%^RESET%^, and you find your gaze drawn to certain focal "+
               "points - a %^BOLD%^%^CYAN%^m%^RED%^u%^MAGENTA%^l%^GREEN%^t"+
               "%^CYAN%^i%^RED%^c%^MAGENTA%^o%^GREEN%^l%^CYAN%^o%^RED%^r"+
               "%^MAGENTA%^e%^GREEN%^d %^WHITE%^lotus blossom %^RESET%^in "+
               "the center contained within a square quartered diagonally "+
               "into planes of %^BOLD%^%^RED%^red%^RESET%^, %^BOLD%^"+
               "%^GREEN%^green%^RESET%^, %^BOLD%^%^CYAN%^blue%^RESET%^, "+
               "and %^YELLOW%^yellow%^RESET%^.  Countless smaller designs "+
               "surround the central panel, creating a truly dizzying "+
               "painting.";
               break;
      case 2:  mypainting = "At first glance, this painting seems simpler "+
               "than the others.  Upon closer inspection, you realize that "+
               "it would have taken an extraordinary amount of time and "+
               "effort to create the spirals in its design.  The outer edge "+
               "of the circular sand painting is %^BOLD%^%^BLACK%^deep "+
               "black %^RESET%^that shifts flawlessly into %^BLUE%^indigo"+
               "%^RESET%^.  The two colors are blended so perfectly that, "+
               "try as you might, you cannot pinpoint any particular spot "+
               "where it shifts from one hue to the next.  The slender spiral "+
               "continues inward, passing through hues of %^MAGENTA%^purple"+
               "%^RESET%^, %^RED%^red%^RESET%^, %^ORANGE%^orange%^RESET%^, "+
               "%^YELLOW%^yellow%^RESET%^, %^GREEN%^green%^RESET%^, "+
               "%^CYAN%^azure%^RESET%^, %^BOLD%^%^BLUE%^blue%^RESET%^, "+
               "and finally back to %^BLUE%^indigo %^RESET%^and %^BOLD%^"+
               "%^BLACK%^black %^RESET%^in the center.";
               break;
      case 3:  mypainting = "An intricate knot design, this painting is "+
               "square-shaped overall.  A background of %^BOLD%^pure white "+
               "sand %^RESET%^provides the base for this complicated "+
               "collection of swooping arcs and points.  Seemingly an "+
               "optical illusion, the 'strands' of the knot are joined "+
               "together so cleverly that you cannot tell where one is "+
               "and another begins despite the many %^BOLD%^GREEN%^c"+
               "%^RED%^o%^BLUE%^l%^MAGENTA%^o%^YELLOW%^r%^CYAN%^s %^RESET%^"+
               "used.";
               break;
      default: mypainting = "This sand painting is a collection of "+
               "repeating geometric designs.  A broad %^MAGENTA%^"+
               "purple square border%^RESET%^ hems in the painting, "+
               "while triangles, diamonds, and countless other shapes "+
               "combine with borders to make this painting look like a "+
               "%^BOLD%^s%^GREEN%^t%^YELLOW%^a%^CYAN%^i%^BLUE%^n%^RED%^e"+
               "%^MAGENTA%^d %^BLACK%^g%^GREEN%^l%^RESET%^%^CYAN%^a%^BOLD%^"+
               "%^RED%^s%^YELLOW%^s %^WHITE%^w%^RESET%^%^MAGENTA%^i%^BOLD%^"+
               "n%^CYAN%^d%^BLUE%^o%^GREEN%^w%^RESET%^.";
               break;
   }
   return mypainting;
}

int sit_em(string str){
string pillow, pillowdec;
   if(!str) return 0;
   if(str == "rug" || str == "on rug" || str == "rugs" || str == "on rugs"){
      tell_object(TP,"%^BOLD%^You find a clear place on the rugs and "+
         "sit, crossing your legs.%^RESET%^");
      if(!TP->query_invis()){
         tell_room(TO,"%^BOLD%^"+TPQCN+" %^BOLD%^%^WHITE%^sits cross legged "+
            "on the pile of rugs.%^RESET%^",TP);
      }
      return 1;
   }
   if(str == "pillow" || str == "on pillow"){
      switch(random(14)){
         case 0:  pillow = "%^RESET%^%^RED%^maroon"; break;
         case 1:  pillow = "%^BOLD%^%^RED%^crimson"; break;
         case 2:  pillow = "%^RESET%^%^BLUE%^indigo"; break;
         case 3:  pillow = "%^BOLD%^%^BLUE%^cobalt"; break;
         case 4:  pillow = "%^ORANGE%^golden"; break;
         case 5:  pillow = "%^YELLOW%^sunny yellow"; break;
         case 6:  pillow = "%^RESET%^%^GREEN%^deep green"; break;
         case 7:  pillow = "%^BOLD%^%^GREEN%^lime green"; break;
         case 8:  pillow = "%^BOLD%^%^BLACK%^sable"; break;
         case 9:  pillow = "%^BOLD%^%^WHITE%^ivory"; break;
         case 10:  pillow = "%^RESET%^%^CYAN%^azure"; break;
         case 11:  pillow = "%^BOLD%^%^CYAN%^sky blue"; break;
         case 12:  pillow = "%^RESET%^%^MAGENTA%^violet"; break;
         default:  pillow = "%^BOLD%^%^MAGENTA%^lilac"; break;
      }
      switch(random(3)){
         case 0:  pillowdec = " with %^YELLOW%^golden tassels"; break;
         case 1:  pillowdec = " with matching fringe"; break;
         default:  pillowdec = ""; break;
      }
      tell_object(TP,"%^BOLD%^%^BLACK%^You pull up a "+pillow+" cushion"+
         "%^BOLD%^%^BLACK%^"+pillowdec+" %^BOLD%^%^BLACK%^and settle "+
         "comfortably onto it.%^RESET%^");
      if(!TP->query_invis()){
         tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" %^BOLD%^%^BLACK%^"+
            "settles comfortably on a "+pillow+" cushion%^BOLD%^"+
            "%^BLACK%^"+pillowdec+".%^RESET%^",TP);
      }
      return 1;
   }
   return 0;
}

int lie_em(string str){
   if(!str) return 0;
   if(str != "rug" && str != "on rug" && str != "rugs" && str != "on rugs") return 0;
   tell_object(TP,"%^CYAN%^You stretch out on the soft rugs, making "+
      "yourself comfortable.%^RESET%^");
   if(!TP->query_invis()){
      tell_room(TO,"%^CYAN%^"+TPQCN+" %^RESET%^%^CYAN%^stretches out "+
         "on the soft rugs, making "+TP->QO+"self comfortable.%^RESET%^",TP);
   }
   return 1;
}

int paint_em(string str){
string mycolor,myshape,myability;
int myscore;
   if(!str){
      tell_object(TP,"You must choose a color to paint with - red, orange, "+
         "yellow, green, blue, azure, indigo, violet, pink, black, or white.");
      return 1;
   }
   switch(str){
      case "with red": mycolor = "%^BOLD%^%^RED%^red"; break;
      case "with orange": mycolor = "%^RESET%^%^ORANGE%^orange"; break;
      case "with yellow": mycolor = "%^YELLOW%^yellow"; break;
      case "with green": mycolor = "%^RESET%^%^GREEN%^green"; break;
      case "with blue": mycolor = "%^BOLD%^%^BLUE%^blue"; break;
      case "with azure": mycolor = "%^RESET%^%^CYAN%^azure"; break;
      case "with indigo": mycolor = "%^RESET%^%^BLUE%^indigo"; break;
      case "with violet": mycolor = "%^RESET%^%^MAGENTA%^violet"; break;
      case "with pink": mycolor = "%^BOLD%^%^MAGENTA%^pink"; break;
      case "with black": mycolor = "%^BOLD%^%^BLACK%^black"; break;
      case "with white": mycolor = "%^BOLD%^%^WHITE%^white"; break;
      default: tell_object(TP,"You must choose to <paint with> a color - "+
         "red, orange, yellow, green, blue, azure, indigo, violet, pink, black, "+
         "or white.");
         return 1;
         break;
   }
   switch(random(5)){
      case 0: myshape = "line"; break;
      case 1: myshape = "zigzag"; break;
      case 2: myshape = "spiral"; break;
      case 3: myshape = "circle"; break;
      default: myshape = "wave"; break;
   }
   myscore = TP->query_stats("dexterity");
   if(TP->is_class("psion")){ 
      myscore += random(5)+1;
   }else if(!random(3)){
      myscore -= random(5)+1;
   }else{
      myscore += random(3);
   }      
   switch(myscore){
      case 0..12: myability = "horribly muddled"; break;
      case 13..14: myability = "reasonably depicted"; break;
      case 15..16: myability = "fairly good"; break;
      case 17..18: myability = "well-formed"; break;
      case 19..20: myability = "nearly perfect"; break;
      default: myability = "flawless"; break;
   }
   tell_object(TP,"Using a chak-pur, you gather "+mycolor+" sand "+
      "%^RESET%^and add a "+myability+" "+myshape+" to one of the "+
      "sand paintings.");
   tell_room(TO,"Using a chak-pur, "+TPQCN+" gathers "+mycolor+" "+
      "sand %^RESET%^and adds a "+myability+" "+myshape+" to one of "+
      "the sand paintings.",TP);
   return 1;
}