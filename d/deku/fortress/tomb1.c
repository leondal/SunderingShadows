#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit TOMB;

int page,being_read;
void do_book_display();

void create() {
  ::create();
    	
    set_long("%^BOLD%^%^WHITE%^The walls, floor, and ceiling of "+
    "this building are coated with a thick layer of "+
    "%^RESET%^%^GREEN%^moss%^BOLD%^%^WHITE%^, which effectively "+
    "masks whatever the substance they are created from is.  "+
    "A large, %^RESET%^stone pedestal%^BOLD%^%^WHITE%^ sleeps in "+
    "the center of the floor.  A heavy, leather bound %^BLUE%^book "+
    "%^BOLD%^%^WHITE%^sits lazily on the top of it.  A "+
    "mysterious %^CYAN%^glowing door%^BOLD%^%^WHITE%^ leads out "+
    "of this building to whatever lies beyond.%^RESET%^");

	set_items(([
    ({"moss","thick moss"}) : "%^GREEN%^This thick, wet, moss "+
    "covers the ceiling, walls, and floor of this building.  "+
    "It lingers everywhere except for on the pedestal and the "+
    "glowing door leaving this building.%^RESET%^",
    
    ({"walls","wall"}) : "%^GREEN%^The walls of this tomb are "+
    "covered with a thick, wet, moss.  The moss successfully "+
    "masks the identity of whatever substance they have "+
    "been constructed from.  Inset in the southern wall is "+
    "a very out of place door that continually glows.%^RESET%^",
    ({"ceiling"}) : "%^GREEN%^The ceiling of this tomb is "+
    "covered with a thick, wet, moss.  The moss sucessfully "+
    "masks the identity of whatever substance the ceiling "+
    "has been constructed from.%^RESET%^",
    ({"floor"}) : "%^GREEN%^The floor of this tomb is covered "+
    "with a thick, wet, moss.  The moss successfully masks "+
    "the identify of whatever substance the floor has "+
    "been constructed from.  A large, stone pedestal sleeps in "+
    "the center of it.%^RESET%^",
    ({"pedestal","large pedestal","stone pedestal"}) : "This large "+
    "pedestal has been carved from a block of large stone.  "+
    "It is of a crude and flawed design and is only identifiable "+
    "by the outline of its shape.  It seems strangely "+
    "out of place here though and the book resting on it "+
    "seems even further out of place.",
    ({"book","large book"}) : "%^BLUE%^Upon closer inspection "+
    "you realize that the front of this leather bound book "+
    "is inscribed with the name '%^RED%^mordavian glan%^RESET%^"+
    "'%^BLUE%^.  It looks quite thick and may contain some "+
    "interesting information.  You could try to %^CYAN%^read"+
    "%^BLUE%^ it.%^RESET%^",
    ]));
    set_exits(([
    "out" : GY_ROOMS+"grave3-6"
    ] ));
    set_door("glowing door",GY_ROOMS+"grave3-6","out");
    set_string("glowing door", "open", "%^CYAN%^The door swings "+
    "silently and effortlessly outward.%^RESET%^");
    set_door_description("glowing door","%^BOLD%^%^CYAN%^This "+
    "glowing door is made from an unknown substance.  It doesn't "+
    "appear to be solid yet somehow it manages to completely "+
    "obscure any attempt at viewing whatever may linger behind "+
    "it.%^RESET%^");
    page = 1;
}

void continue_reading(string str) {
    if(str == "y" || str == "yes") {
        page++;
        write("You flip to the next page.");
        tell_room(TO,TPQCN+" flips to the next page in the "+
        "book.",TP);
        do_book_display();
        return;
    }
    if(str || !str) {
        write("You shake your head and close the book.");
        tell_room(TO,TPQCN+" shakes "+TPQP+" head and closes "+
        "the book, stepping away from the pedestal.",TP);
        page = 1;
        being_read = 0;
        return;
    } 
}     

void do_book_display() { 
    write("%^BLUE%^==========================================="+
    "=================%^RESET%^\n");
    write("%^RED%^                  Page "+page+"%^RESET%^");
    write("%^BLUE%^==========================================="+
    "=================%^RESET%^\n");
    if(page == 1) {
        write("I have written this as a "+
        "remembrance to you my dear friend "+
        "Mordavian.  I know that you shall "+
        "never inherit this tomb.  I would "+
        "rather that you lived many years "+
        "and found your rest here only after "+
        "a lifetime of beauty!  Oh, Mordavian! "+
        "How my heart aches because of your "+
        "fate.  I sorely wish that I could "+
        "have helped prevent your fate.... "+
        "Nevertheless, I shall not lose my "+
        "resolve, this book is for you.  "+
        "To tell others of what happened to "+
        "you, to never let the truth be forgotten.  "+
        "I shall make you proud my dear friend.");
     }
     if(page == 2) {
        write("The story of Mordavian Glan "+
        "begins some centuries ago.  It is, "+
        "unfortunately, not a long one but "+
        "none the less.... troubled, yes, "+
        "troubled, with all too much drama.  "+
        "Mordavian and I were young boys "+
        "living in the prosperous village of "+
        "verbobone.  He was the son of the "+
        "headman of the village.  They lived in "+
        "the only mansion in the town!  Oh, how "+
        "beautiful it was!  Even in such a small "+
        "village there was never a shortage "+
        "of trouble, but the island of deku "+
        "was peaceful and at rest.  Many peoples "+
        "living across it, with relatively "+
        "few hidden pitfalls and some exciting "+
        "places to explore.  Suddenly, the "+
        "village began to experience strange "+
        "troubles.  Diseases that the healer "+
        "could not cure, creatures that were "+
        "not of this world, unsolved deaths in "+
        "the midst of the night.  The headman "+
        "suspected his own brother... I don't "+
        "know of their history, but I expect it "+
        "was a very troubled one as well.  Dear "+
        "Mordavian was close to his uncle and torn "+
        "by the accusations his father brought "+
        "against him.  My friend, however, was "+
        "not terribly suprised, as his uncled "+
        "had requested much of him in recent time, "+
        "he'd asked him strange questions and "+
        "commanded him to do strange things.  "+
        "No, he was not really suprised, just "+
        "torn.%^RESET%^");
      }
     if(page == 3) {
        write("Several months went by after "+
        "the accusations and there were no "+
        "more strange events.  All of them simply "+
        "stopped, seemingly more proof of the "+
        "guilt of Kiomanl Glan's guilt "+
        "(mordavians' uncle).  Then SHOCK!  "+
        "Mordavian's mother had been caught in "+
        "an adulterous affair with Kiomanl and "+
        "his father left, in anger, vanishing "+
        "into the forest.  Mordavian was devasted, "+
        "his world had been torn asunder, "+
        "nothing was the same anymore.  He began "+
        "having troubling visions, of things not "+
        "of this world.  He saws ghosts, fiery "+
        "creatures, creatures that should have "+
        "been dead but where not.  He even "+
        "confided to me that he had been awakened "+
        "several times during the night by "+
        "bizaare sounds.  I had replied that "+
        "it was perhaps his uncle and mother, "+
        "but he argued vigirously that something "+
        "was terribly amiss and that somehow the "+
        "visions and sounds were intertwined.");
      }
      if(page == 4) {
        write("I have written so much about the "+
        "trouble that was your life my friend.  I "+
        "am sorry that it must be this way.... we "+
        "were so young when the tragedy struck your "+
        "world.. and I have never once forgotten you "+
        "or given up hope that someday I can find a "+
        "way to free you from your present torment.");
      }
      if(page == 5) {
        write("Months pasted, Mordavian and I "+
        "spoke often of the strangeness that "+
        "had became his life.. but never "+
        "were we able to do anything about it.  "+
        "I suppose we found a happy middle ground "+
        "between the life we once had and what it "+
        "had became.  The strangeness was a sort "+
        "of joke to us or rather we made it humorous "+
        "to ease the pain, I suppose.  It was "+
        "after this that the horror occured.... "+
        "Mordavian was awokened with a start one "+
        "night.  His house was overrun by strange "+
        "creatures, and that night his fate was "+
        "forever changed.  I know none of the "+
        "specifics, only that my friend ended "+
        "that night mutated and mutilated, changed "+
        "beyond what I can reason.");
       }
       if(page == 6) {
        write("Mordavian!  Oh, how twisted that "+
        "night left you, how I ache for you my "+
        "friend!  I have never quit seeking a way "+
        "to help you... Now.. under that house... "+
        "you rest.... twisted and outcast.  "+
        "**The rest of the page is smeared with a thick "+
        "dark substance.**");
       }
     write("%^BLUE%^==========================================="+
     "=================%^RESET%^\n");
       if(page == 6) {
        write("You realize that, strangely, the rest of the "+
        "book is filled with blank pages.");
         write("You shake your head and close the book.");
        tell_room(TO,TPQCN+" shakes "+TPQP+" and then closes "+
        "the book, stepping away from the pedestal.",TP);
        page = 1;
        being_read = 0;
        return;
        }
        write("Will you continue reading?  %^CYAN%^yes%^RESET%^ "+
        "or %^CYAN%^no%^RESET%^?");
        input_to("continue_reading",0);

}

__Read(string str) {
    if(!str) return 0;
    if(str == "book") {
        if(being_read == 1) {
            tell_object(TP,"Someone else is near the book "+
            "and reading it.");
            return 1;
        }
        tell_object(TP,"You walk up to the pedestal and flip open "+
        "the book to the first page.");
        tell_room(TO,TPQCN+" walks up the pedestal and flips the "+
        "book open to the first page.",TP);
        do_book_display();
        being_read = 1;
        return 1;
    }
    return 0;
}

void reset() {
    object ob;
    ::reset();
    if(!random(2) && !present("charred mohrg")) {
        ob = new(GY_MOBS+"mohrg");
        ob->make_me(1);
        ob->move(TO);
    }
    if(!random(2) && !present("crimson mohrg")) {
        ob = new(GY_MOBS+"mohrg");
        ob->make_me(0);
        ob->move(TO);
    }
}

  
