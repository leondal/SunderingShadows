#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("readpage_fun","read");
}
void create() {
    ::create();
    set_name("note");
    set_id(({"note"}));
    set_short("%^RESET%^%^GREEN%^A note page from a journal%^RESET%^");
    set_long(
	"%^MAGENTA%^This is a note page that was torn from a journal. There "
	"is much writing covering it which can be read."
	"%^RESET%^"
    );
    set_weight(1);
    set_value(5);
}
int readpage_fun(string str) {
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(str != "page" && str != "note") {
	notify_fail("Read what?\n");
	return 0;
    }
    write("%^RED%^The note scrawled in black ink reads:\n"
	"\n%^BOLD%^%^BLUE%^"
	"that which beings of power over undeath and Necromantic magic can\n"
	"learn to pass into not the mortal death, nor the unknown and enslaved\n"
	"undeath which so many pitiful mortals find through their own misfortune\n"
	"to be trapped within, but true undeath, the power to live and rule\n"
	"forever. It was such souls that inhabited the Vampyres I discovered\n"
	"through my dream talks with the creature I so wantingly hunted.\n"
	"It and it's brothers had chosen their forms well in a living state,\n"
	"something which surprised me...so far I had only gained knowledge\n"
	"of enslaving the living into my control as undead. The idea of\n"
	"purposely transforming myself into a creature of the night startled\n"
	"me, but as the days waned on I began to become overcome with an\n"
	"immense desire, a overwhelming obession encompassed me to find the\n"
	"knowledge of the transition. Despite my obsessed state of mind I\n"
	"still knew that my hunted companion (yes now he had become more\n"
	"a companion than a foe) faced a grave danger in choosing his form\n"
	"of undeath.\n"
	"     Through my talks with him I had discovered that a mortal who\n"
	"choose to escape the grips of death and to walk the lands willingly\n"
	"and under ones own control had but one fear...to be destroyed as\n"
	"an undead of such form meant permanent enslavement and torment by\n"
	"all souls you might happen to feed upon while in the undead state.\n"
	"This is why the Vampyre was so careful to convince me to befriend\n"
	"him, for his strength had grown so much that I was one of the last\n"
	"mortal beings capable of ending his existance and condemning him\n"
	"to Limbo. He had made a choice for his form, and a powerful choice\n"
	"it was, especially since he had been a far weaker mortal than I was\n"
	"in my own life. But if I was to risk all for the power of eternal\n"
	"life through death than it was obvious I must choose an even higher\n"
	"form than a Vampyre. I needed a form that would allow me to transfer\n"
	"all the power I carried within life with me to my undead state of\n"
	"being. There is only one creature of the night, only one form which\n"
	"can grant just that, only one guise offers such overwhelming power\n"
	"to be coupled with all the power one held within their mortal life.\n"
	"And such a form and only ever been achieved through accident or\n"
	"through a wretched curse of some twisted god. But the secret exists\n"
	"for one to obtain, my companion informed me. It was in that last\n"
	"dream visitation that I was made aware of all this. I awoke enthralled\n"
	"and blinded with a tunnel vision. So excited I was, I failed to notice\n"
	"how much the sun had begun to hurt my eyes. My companion had informed\n"
	"me of small, but necessary, components and ingredients I would need\n"
	"and spent most of the day gathering those in a fever. It was later\n"
	"that night that my companion visited me, not in my dreams, but while\n"
	"I was smoking my pipe and musing over all I had learned.\n"
	"     I did not hear or see him enter. In fact the hounds and mastiffs\n"
	"lay still in sleep by the hearth as I felt his cold touch upon my\n"
	"\n%^RED%^(The page ends here.)"
    );
    say("%^RED%^"+TPQCN+
        " reads over a page of writing for a few minutes, then looks up with "
	"a troubled look in "
	+TP->query_possessive()+
	" eyes.%^RESET%^"
    ,TP);
    return 1;
}

	
