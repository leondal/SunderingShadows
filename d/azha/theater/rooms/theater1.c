#include <std.h>
#include "../theater.h"
//Thanks to Ares who helped with all the message and keys!\\

#define MESSAGE ({"%^BOLD%^%^WHITE%^The instrument locks into place in the statue's hands.",\
"%^BOLD%^%^WHITE%^A groaning creaking noise disturbs the peace of the courtyard.",\
"%^CYAN%^Metal grinding against metal screeches.",\
"%^BOLD%^%^CYAN%^Spouts inside the fountain slowly open up.",\
"%^BOLD%^%^CYAN%^Water begins to trickle out of the spouts and into the fountain.",\
"%^BOLD%^%^BLUE%^The dirt and debris inside the fountain mixes with the cloudy water.",\
"%^BOLD%^%^CYAN%^The water starts to rise within the basin.",\
"%^BOLD%^%^WHITE%^The marble basin begins to creak and groan.",\
"%^BOLD%^%^CYAN%^The water rises higher until it fills the basin.",\
"%^RED%^A dark red aura surrounds the statue.",\
"%^BOLD%^%^RED%^With stiff slow motions the statue begins to move!",\
"%^BOLD%^%^WHITE%^Flecks of marble fall away from the statue revealing flesh underneath the marble casing.",\
"%^BOLD%^%^GREEN%^The statue lets out a scream as she throws her hands back, freeing herself from the marble prison.",\
"%^MAGENTA%^Casting her eyes at you, the female smirks as she unfolds her feather wings and lifts herself into the air.",\
"%^MAGENTA%^Mashiva says in a sultry voice:%^CYAN%^ After how many years.. I am free again!",\
"%^MAGENTA%^Mashiva says in a sultry voice:%^CYAN%^  Let me reward your for your deed today..",\
"%^MAGENTA%^Mashiva says in a sultry voice:%^CYAN%^ By becoming my feast!",\
"%^BOLD%^%^CYAN%^The winged woman reaches into the thin air and retrieves weapons to aid her."})

void set_key();
int check_key(string instrument);
void replace_instrument(string instrument);
void creepy_message(int message_number);

inherit ROOM;
int FLAG;
string statue_key;

	void create(){
   	::create();
   	set_property("indoors",0);
   	set_property("light",2);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^The Desert Sun - Courtyard");
   	set_short("%^RED%^The Desert Sun - Courtyard");
   	set_long("%^ORANGE%^Stepping into the courtyard of "+
		"the theater, you feel a slight chill.  The air here"+
		" within the courtyard seems different, almost colder"+
		" than the warmth of the plaza you left.  The flagstone"+
		" courtyard is in a state of disrepair, like the rest of"+
		" the district about you.  %^GREEN%^Weeds%^ORANGE%^ and"+
		" %^GREEN%^grass%^ORANGE%^ push through the cracks in the"+
		" paved stone courtyard.  Twisted and tangled %^GREEN%^bushes"+
		" %^ORANGE%^and %^GREEN%^trees%^ORANGE%^ grow wild with no one"+
		" to tend them.  In the center of the courtyard an empty %^RESET%^"+
		"marble%^ORANGE%^ fountain rests.  Smooth steps rise west, leading"+
		" to the theater.  The %^YELLOW%^sandstone%^RESET%^%^ORANGE%^ "+
		"theater retains a majestic quality that the"+
		" rest of this district does not.  Supporting the roof of this "+
		"performance hall are a series of %^YELLOW%^statues%^RESET%^%^ORANGE%^"+
		".  Hanging from their hinges are a pair of %^YELLOW%^brass"+
		"%^RESET%^%^ORANGE%^ doors that lead "+
		"inside the theater, though from here it's hard to see inside.  "+
		"A %^RED%^m%^YELLOW%^o%^RED%^s%^RESET%^%^ORANGE%^a%^RED%^i%^YELLOW%^c"+
		"%^RESET%^%^ORANGE%^ of a fiery sun has hangs over the entrance to the"+
		" theater.  \n");
   	set_smell("default","A stale musty scent hangs in the air.");
   	set_listen("default","The courtyard is quiet.");
  	set_items(([
      	({"fountain"}) : "%^BOLD%^Crafted from marble, this weathered fountain"+
	" is round in shape.  A relief of minstrels playing all manner of "+
	"instruments circles around the base of the fountain.   Water stains"+
	" cover the interior of the fountain, dulling the white marble to a "+
	"dingy %^RESET%^gray %^BOLD%^color.  Rising from the center of"+
	" the fountain is a statue"+
	" of a female human.  The statue is posed as if in the middle of "+
	"playing an instrument, though her hands are empty now.  The female figure is "+
	"carved to look as if she's wearing a feather cloak over her clothing"+
	".  Her short "+
	"%^BOLD%^%^BLACK%^black hair%^BOLD%^%^WHITE%^ spirals in "+
	"tight curls around her face.  "+
	"Dried %^GREEN%^palm leaves%^WHITE%^ litter the inside of the fountain.",
      	({"statues","statue","figures"}) : "%^BOLD%^Which statues would you like "+
	"to look at?  You can look at the %^MAGENTA%^left statues%^WHITE%^,%^YELLOW%^"+
	" the fountain%^WHITE%^ or the"+
	" %^CYAN%^right statues%^WHITE%^.",
		({"right statues"}) : "The column like figures that support "+
	"the roof of the theater are made from sandstone.  An equal number"+
	" of male and female statues flank the brass doors.  The statues are"+
	" carved to represent the embodiments of performing arts.  To the right"+
	" of the %^YELLOW%^brass%^RESET%^ doors is a male figure playing a "+
	"%^CYAN%^flute%^RESET%^ and dressed in a short toga, representing "+
	"%^CYAN%^musicians%^RESET%^.  To his right rests a male figure dressed"+
	" in a long flowing robe holding a %^RED%^quill%^RESET%^ and "+
	"%^RED%^parchment%^RESET%^, representing %^RED%^prose%^RESET%^.  Next"+
	" to this figure is another male figure holding the %^MAGENTA%^masks"+
	" of tragedy and comedy%^RESET%^ over his long toga, representing "+
	"%^MAGENTA%^drama%^RESET%^.",
		({"left statues"}) : "The column like figures that support"+
	" the roof of the theater are made from sandstone.  An equal number"+
	" of male and female statues flank the brass doors.  Nearest the"+
	" %^YELLOW%^brass%^RESET%^ doors on the left side features a statue"+
	" of a female clothed in a flowing sleeveless gown, her lips parted "+
	"as if captured in the middle of a %^GREEN%^song%^RESET%^, representing"+
	" %^GREEN%^ singers%^RESET%^.  To her left is a female in a long toga "+
	"holding a %^BOLD%^%^BLUE%^peacock feather quill%^RESET%^ and %^BOLD%^"+
	"%^BLUE%^parchment%^RESET%^, representing %^BOLD%^%^BLUE%^poetry%^RESET%^."+
	"  Next to her is a female figure dressed in a gauzy multi-layered robe,"+
	" her posture looking as if she is ready to move at any moment, representing"+
	" %^BOLD%^%^MAGENTA%^dance%^RESET%^.  At one time it was believed that "+
	"these six figures served the gods Oghma and Lathander as the Muses of"+
	" Performing Arts.",
		({"plants","trees","bushes","garden"}) : "%^GREEN%^Tall palm trees grow"+
	" wild among the verdant green bushes and garden.  The garden itself "+
	"looks as if it might have at one time been well cared for and meticulously"+
	" manicured.  Now the flowers and plants look wild and untamed.",
		({"mosaic"}) : "Crafted from %^YELLOW%^gold%^RESET%^"+
	" and precious and semi-precious gems,"+
	" the mosaic that adorns the theater features the image of a %^BOLD%^"+
	"%^RED%^fiery red sun%^RESET%^ setting behind rolling%^ORANGE%^ desert"+
	" dunes%^RESET%^.  The light catches the facets of the %^BOLD%^%^RED%^"+
	"rubies%^RESET%^, %^RED%^garnets%^RESET%^, %^BOLD%^%^RED%^fire opal"+
	"%^RESET%^, %^RED%^red jasper%^RESET%^,%^ORANGE%^ topaz%^RESET%^,"+
	"%^BOLD%^%^MAGENTA%^ pink %^RESET%^and %^YELLOW%^canary%^RESET%^ "+
	"diamonds causing the sun to almost shine.  Strange that an area in"+
	" such disrepair and ruins has left such precious gems untouched.",
		({"doors","brass doors"}) : "%^YELLOW%^Twin large brass doors hang "+
	"from their hinges, looking as if they were nearly ripped right off."+
	"  The brass doors are trimmed with a geometric border around their edge with"+
	" stylized six pointed star and five petal floral shapes filling the"+
	" interiors.  It's to dark to gain much detail about the inside of "+
	"the theater.",
	]));
	set_exits(([ "east" : ROOMDIR"calim8",
			 "inside" : ROOMDIR"theater2",
	]));
    
    	set_key();//sets the instrument to be used once per reboot
	}

void init(){
    ::init();
    	add_action("replace_instrument","replace");
    return;
}
void set_key()// needs to be called only 1 time, inside of create
{
	switch (random(3))// this will set the instrument needed to be random
    	{
case 0:
    	statue_key = "marble lute";
break;
case 1:
    	statue_key = "marble flute";
break;
case 2:
    	statue_key = "marble lyre";
break;
    	}
  	return;
}

int check_key(string instrument)
{
    if(instrument == "lute" || instrument == "marble lute")
    {
        if(statue_key == "marble lute" && present("marble lute",TP))
        {
            present("marble lute",TP)->remove();
            return 1;
        }
        else return 0;
    }

    if(instrument == "flute" || instrument == "marble flute")
    {
        if(statue_key == "marble flute" && present("marble flute",TP))
        {
            present("marble flute",TP)->remove();
            return 1;
        }
        else return 0;
    }

    if(instrument == "lyre" || instrument == "marble lyre")
    {
        if(statue_key == "marble lyre" && present("marble lyre",TP))
        {
            present("marble lyre",TP)->remove();
            return 1;
        }
        else return 0;
    }
    return 0;
}

void replace_instrument(string instrument)
{
    if(!instrument) return notify_fail("What are you trying to replace?\n");

    if(instrument != "lute" && instrument != "flute" && instrument != "lyre" && instrument != "marble lute" && instrument != "marble flute" && instrument != "marble lyre")
        return notify_fail("Replace what?\n");

    if(!check_key(instrument))
    {
        return notify_fail("That instrument doesn't seem to be the right one.\n");
    }

    creepy_message(0);

    return 1;
}

void creepy_message(int message_number)
{
    if(message_number < sizeof(MESSAGE)) 
    {        
        tell_room(TO, MESSAGE[message_number]+"\n");
        message_number++;
        call_out("creepy_message",4,message_number);// creepy_message is the function, 3 is the delay, and message_number is which message it sends
        return;
    }

    new(MOB"mashiva.c")->move(TO);
    return;
}
        


