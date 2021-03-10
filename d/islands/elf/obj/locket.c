#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
   ::create();
   set_name("locket");
   set_id(({"locket","tarnished locket","cerilana's locket","elfquestlocket"}));
   set_short("%^MAGENTA%^Ce%^RESET%^r%^MAGENTA%^ilana's loc%^RESET%^k%^MAGENTA%^et%^RESET%^");
   set_obvious_short("%^MAGENTA%^ta%^RESET%^rn%^MAGENTA%^ished l%^RESET%^oc%^MAGENTA%^ket%^RESET%^");
   set_lore("Cerilana was an half-elf of a strange legend."+
   "   Both her human family and her elven family were "+
   "ruined during the war.  Stories are told to make "+
   "children behave that at night she can be heard "+
   "wailing in mourning for her loss outside the "+
   "town.   It looks like there is some truth behind these tales. ");
   set_property("lore difficulty",30);
   set_long("%^MAGENTA%^This is a tarnished silver locket."+
   "  It has a hook on the back and a matching tarnished "+
   "silver necklace can be hooked around the wearer's neck."+
   "  The locket itself can be opened.  There is a painting"+
   " of four people in it.  The adults are an elf and"+
   " a human, and two children one male and one female. "+
   " They look to be half-elven.%^RESET%^");
   set_size(-1);
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",4+random(2));
   set_item_bonus("spell damage resistance",20);
   set_item_bonus("negative energy resistance",10);
   set_item_bonus("positive energy resistance",-10);
}

int wear_me(){ 
  tell_object(ETO,"%^MAGENTA%^You secure the locket around your neck and it seems like ages last you saw your family.");
         if(find_call_out("mess")==-1)  
           call_out("mess",120+random(1000)); 
  return 1;
}

void mess() {
    int i;
    object *msgs;
	if(!objectp(EETO)) return;
    if(!query_worn() || !ETO) return;
	new("/cmds/priest/obj/dark")->move(EETO);
	tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" blinks as a tear drops from "
	+ETO->QP+" eye.  It falls to the ground and becomes a globe of darkness.",ETO);
        msgs = ({"I miss my family, why did they have to be taken away?",
"Where is my brother, have you seen him?",
"My brother, I miss him so.",
"The darkness it will never go away.  There will never be another day.",
"The despair, it consumes me."
"I wander looking for my brother.  Where is he?  I've been looking for so long.",
"They took my mother from us, then they took my father, my brother is all that is left.  I must find him."
"My mother wished for peace, my father as well.  Why did they have to die?"
"If you don't have someone to protect, are you even alive?",
"I just want to find my brother.  Is that so much to ask?",
"The elven world, the human world, there is no place for one such as I in either.",
"The elves saw me as less than a person, the humans as a spy, the only one who I can trust is my family.  Where did they go?",
"When will the darkness end?  I can't see anything.",
"If I was left alone I would surely perish.",
"My brother, he must be found.  I will never give up the search.",
"I mourn for my dead mother and father.  My brother I'm sure he does as well.  Where can he be?",
"When will the search end?  It seems like it has been an eternity.",
"Brother, please be safe.  Stay away from the fate of the rest of our family.",
"Father was kind, mother as well. Why did they have to be murdered? Why must we be left alone?",
"This war, it will never end, thousands have died, thousands more will die.",
"I am so alone...so alone.",
"It is cold, so cold.",
"My soul it is empty, I can't feel anything.",
"Please brother, you can come out of hiding.  It is your sister...I am here.",  
"It is like I'm in a dream . . . when will I wake?",
"The night is so long, I fear the sunrise that follows.",
"The fog is so thick, every direction I wander is the same.",
"I wish I could rest.  How long has it been?",
"My brother, he searches for me now.",
"Brother, we will be united.  I won't give up.",
"I feel like I'm freezing, everything has gone numb.",
"Father couldn't stop the war, he tried but died.",
"This vast emptiness is like a sea with no end.",
"This despair, it is like a hunger that can never be sated.",
"Mother, you loved us, why did they take you away?",
"I feel invisible.  Everyone looks away from me.",
"I fear the light, it will shine through my hollow form. Nothing will be left.",
        });
 write("%^CYAN%^Someone whispers to you:%^RESET%^ "
   +msgs[random(sizeof(msgs))]);
 call_out("mess",120+random(1000)); 
return;
}
