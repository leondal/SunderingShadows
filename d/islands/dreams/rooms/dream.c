#include <std.h>
#include "../defs.h"
inherit ROOM;
int FLAG;
void create()
{
  	::create();
  	set_terrain(BEACH);
  	set_travel(FOOT_PATH);
  	set_property("indoors",1);
  	set_property("light",2);
	set_property("no scry",1);
   	set_property("no teleport",1);
 	set_short("%^BOLD%^%^BLUE%^Within the Dreamscape%^RESET%^");
 	set_long("%^CYAN%^All around a vast endlessness of shifting"+
		" shades of darker %^BLUE%^b%^BOLD%^l%^RESET%^%^BLUE%^u"+
		"%^BOLD%^e%^RESET%^%^BLUE%^s%^CYAN%^ rests.  No beginning"+
		" nor no end can be found within the blue field.  A large "+
		"waning %^MAGENTA%^lavender%^CYAN%^ and %^BOLD%^%^BLUE%^blue"+
		"%^RESET%^%^CYAN%^ hued crescent moon hangs in the sky.  "+
		"Ribbons of a gently flowing %^RESET%^liquid%^CYAN%^ fall "+
		"from the sky and cascade over and down the crescent moon;"+
		" fading away as it reached the lower portions of the void."+
		"  Suspended from %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v"+
		"%^BOLD%^e%^BOLD%^r%^RESET%^y%^CYAN%^ threads, ten snowflake"+
		" shaped %^BOLD%^%^WHITE%^stars%^RESET%^%^CYAN%^ hang in the "+
		"sky, providing soft lighting to the dream like landscape.  "+
		"Large %^BOLD%^%^WHITE%^chrysanthemum%^RESET%^%^CYAN%^ flowers"+
		" float in the air mixing with the equally large %^RESET%^lily "+
		"pads%^CYAN%^.  The floating pads and white flowers resemble "+
		"islands in some fashion, looking as if they could hold numerous"+
		" people, leading to a %^BOLD%^%^WHITE%^c%^CYAN%^r%^WHITE%^yst"+
		"%^CYAN%^a%^WHITE%^l%^RESET%^%^CYAN%^ gazebo that floats in the air."+
		"  The gazebo is held afloat by spiraling ethereal "+
		"%^BOLD%^%^BLUE%^t%^CYAN%^e%^MAGENTA%^n%^BLUE%^d%^CYAN%^r%^MAGENTA%^"+
		"i%^BLUE%^l%^CYAN%^s%^RESET%^%^CYAN%^, the tendrils rise up to the"+
		" large %^BOLD%^%^WHITE%^chrysanthemum%^RESET%^%^CYAN%^ flower above"+
		" the gazebo before fanning out to either side creating two %^BLUE%^"+
		"cresting wave%^CYAN%^ like shapes.  Rising off the petals of the "+
		"chrysanthemum are six round orbs that shed a pale %^BOLD%^%^MAGENTA%^"+
		"l%^RESET%^%^MAGENTA%^i%^BOLD%^l%^RESET%^%^MAGENTA%^a%^BOLD%^c"+
		"%^RESET%^%^CYAN%^ glow, illuminating the %^BOLD%^%^WHITE%^lotus "+
		"blossom%^RESET%^%^CYAN%^ that emerges from the larger flower.  The"+
		" petals of the lotus blossom fold inwards to support a %^BOLD%^%^WHITE%^"+
		"s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^y%^RESET%^%^CYAN%^"+
		" ethereal pedestal that supports a large round pale %^MAGENTA%^violet"+
		"%^RESET%^ orb.  %^BOLD%^%^WHITE%^S%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^"+
		"e%^RESET%^r%^BOLD%^y white%^RESET%^%^CYAN%^ motes of light hover in"+
		" the void, winking in and out of existence.\n");       
  	set_smell("default","%^MAGENTA%^The fragrant scent of lotus and chrysanthemums"+
		" lingers in the void.");
  	set_listen("default","%^BOLD%^%^CYAN%^A tranquil stillness brings a feeling"+
		" of serenity to the void.");
  	set_items(
   	 ([
  	({"lotus","lotus flower","violet orb","orb"}) : "%^BOLD%^%^WHITE%^A white"+
		" lotus flower rises from the center of the massive chrysanthemum.  "+
		"The lotus blossoms looks as if it is ready to bloom at any moment."+
		"  The petals curve inwards to hold a silvery pedestal afloat.  "+
		"Resting on the silvery pedestal is a large round "+
		"%^RESET%^%^MAGENTA%^violet%^BOLD%^%^WHITE%^ orb that radiates a"+
		" strong sense of magic.  The violet orb almost seems to resemble"+
		" a portal, you can't help but think. You wonder if entering will"+
		" lead out of this strange place.",
    	({"chrysanthemum", "lilac orbs", "orbs"}) : "%^BOLD%^%^WHITE%^Hovering over"+
		" the crystal gazebo is this large chrysanthemum.  The massive "+
		"flower seems as if it held in place in the void by the "+
		"spiraling tendrils of colors below it.  Encircling the flower"+
		" are %^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^i%^BOLD%^l%^RESET%^"+
		"%^MAGENTA%^a%^BOLD%^c%^WHITE%^ orbs of light rest on ethereal "+
		"pedestals, bathing the white petals of the flower in their glow."+
		"  Rising from the center of the chrysanthemum is the bud of a "+
		"lotus flower, looking ready to bloom at any moment.",
  	({"chrysanthemums", "lily pads"}) : "%^BOLD%^%^WHITE%^The large flowers"+
		" and lily pads float along the lower portion of the void, "+
		"creating a pathway to the gazebo.  The flowers and pads sway"+
		" softly along the void, but seem to be held in place by some"+
		" unseen force.",
	({"gazebo","tendrils"}) : "%^CYAN%^A cylindrical %^BOLD%^%^CYAN%^"+
		"crystal%^RESET%^%^CYAN%^ gazebo rests at the base of the "+
		"flower islands.  Hovering in the void and held in place by"+
		" spiraling %^BOLD%^%^BLUE%^t%^CYAN%^e%^MAGENTA%^n%^BLUE%^d"+
		"%^CYAN%^r%^MAGENTA%^i%^BLUE%^l%^CYAN%^s%^RESET%^%^CYAN%^ of "+
		"colors, the gazebo has a mystical dreamlike feeling to it.  "+
		"The crystal panels of the gazebo allow for a peek at the "+
		"empty interior.",
	({"stars","snowflakes","threads"}) : "%^BOLD%^%^WHITE%^Held aloft"+
		" in the blue void by silver threads are ten large snowflake"+
		" shaped stars.  The stars sparkle with gentle silvery glow.",
	({"moon","crescent moon","liquid","ribbons"}) : "%^CYAN%^The large"+
		" waning %^MAGENTA%^lavender%^CYAN%^ and %^BOLD%^blue"+
		"%^RESET%^%^CYAN%^ crescent moon hangs high in the void on "+
		"your right.  Bright sparks of %^BOLD%^%^MAGENTA%^pink"+
		"%^RESET%^%^CYAN%^, %^MAGENTA%^violet%^CYAN%^, and "+
		"%^BOLD%^%^CYAN%^light blue%^RESET%^%^CYAN%^ roll off the "+
		"surface of the crescent moon before they vanish in the blue"+
		" void.  Ribbons of a %^RESET%^milky liquid%^CYAN%^ fall "+
		"from some unseen source, over the crescent moon and "+
		"plunge down into the void.  The liquid fades in volume"+
		" as it makes its descent until it vanishes away.",
    	]) );
}
void init(){
::init();
    	add_action("enter","enter");
}
int enter(string str){
        if(str != "portal" && str != "orb" && str != "violet orb") 
      return notify_fail("What do you wish to enter?\n");
	if(FLAG){ tell_object(TP,"%^MAGENTA%^The way to the portal is clear now."); 
	return 1; }

      tell_object(TP,"%^CYAN%^%^BOLD%^As you float up to the orb"+
		" the air begins to shimmer with a prismatic mist. "+
		"As you draw closer to the portal from the mist a dragon emerges!");
	tell_room(ETP,"%^BOLD%^%^CYAN%^%^"+TPQCN+" floats up to the "+
		"violet orb as the air begins to shimmer with a "+
		"prismatic mist.  As "+TP->QS+" draws closer to the "+
		"portal a dragon emerges from the mist!",TP);
	tell_room(ETP,"%^BOLD%^%^The dragon hovers in front of the orb,"+
		" blocking it off from you.");
		new(MON+"aislinn")->move(this_object());
    		present("aislinn")->force_me("kill "+TP->query_name()+"");
		tell_room(ETP,"%^BOLD%^%^BLUE%^The dragon moves to attack!");
		add_exit(ROOMDIR"hut","portal");
			FLAG=1;
                	return 1;
}

void reset(){
	::reset();
	FLAG=0;
   		switch(random(5)){
case 0:  tell_room(TO,"%^BOLD%^A silvery mote of light winks into existance near you and then fades.");
	break;
case 1:  tell_room(TO,"%^BLUE%^The milky ribbons of liquid silently cascades over the cresent moon.");
	break;
case 2:  tell_room(TO,"%^BOLD%^%^CYAN%^The colors of the etheral tendrils are reflected off of the crystal gazebo.");
      break;
case 3: tell_room(TO,"%^BOLD%^%^WHITE%^Drops of light fall from the stars and then fade away.");
	break;
case 4: tell_room(TO,"%^MAGENTA%^The violet orb pulsates and glows.");
	break;
   		}
}
