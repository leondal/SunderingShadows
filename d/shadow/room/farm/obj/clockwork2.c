#include <std.h>
inherit OBJECT;
void make_me();

#define types ({"rabbit","cat","dog","pig","cow","squirrel","songbird","orange"})

string type;

void create(){
   int x;
   x = random(sizeof(types));
   type = types[x];
   ::create();
   set_lore("Crafted by Piaf Huffelmuffin, this clockwork "+
      "figurine is a rare treat.  Often given to special "+
      "people as well as nobles and royalty, Piaf's clockwork"+
      " figurines are a cherished treasure.  Using secret methods"+
      " that only he knows, Piaf is able to give a sentient quality"+
      " to his figurines.\n");
   set_property("lore difficulty",7);
   set_weight(3);
   set_value(275);
   switch(type){
      case "rabbit":
	set_long("%^ORANGE%^Made entirely of bronze this clockwork"+
		" rabbit is highly detailed.  The body of the rabbit is "+
		"shaped from a solid piece of bronze, providing stability."+
		"  Hollowed bronze feet have been attached internally to the"+
		" rabbit's torso.  The long eared rabbit's head rises out of "+
		"the bronze torso.  %^BOLD%^%^CYAN%^Blue topaz%^RESET%^%^ORANGE%^"+
		" chips have been used for the rabbit's eyes.  Three long whiskers"+
		" are attached on either side of a painted %^BOLD%^%^MAGENTA%^"+
		"pink%^RESET%^%^ORANGE%^ nose.  A bronze knob juts out of the "+
		"left torso of the rabbit.  Perhaps you can wind it to see what"+
		" the rabbit might do.\n");
   	set_name("clockwork rabbit");
   	set_short("%^RESET%^%^ORANGE%^A clockwork rabbit%^RESET%^");
     	set_id(({"rabbit","clockwork rabbit","clockwork"}));
      break;
   case "cat":
      set_long("%^ORANGE%^Made entirely of bronze this clockwork cat "+
		"is highly detailed.  The body of the cat is shaped from a "+
		"solid piece of bronze, providing stability.  Hollowed bronze"+
		" feet have been attached internally to the cat's torso.  The"+
		" cat's head rises out of the bronze torso.  %^YELLOW%^Tiger "+
		"eye%^RESET%^%^ORANGE%^ gems have been used for the cat's eyes."+
		"  Three longs whiskers are attached on either side of the "+
		"triangular %^BOLD%^%^MAGENTA%^pink%^RESET%^%^ORANGE%^ nose."+
		"  A bronze knob juts out of the left torso of the cat. Perhaps"+
		" you can wind it to see what the cat might do.\n");
   	set_name("clockwork cat");
   	set_short("%^RESET%^%^ORANGE%^A clockwork cat%^RESET%^");
     	set_id(({"cat","clockwork cat","clockwork"}));
      break;
   case "dog":
      set_long("%^ORANGE%^Made entirely of bronze this clockwork dog "+
		"is highly detailed.  The body of the dog is shaped from a "+
		"solid piece of bronze, providing stability.  Hollowed bronze"+
		" feet have been attached internally to the dog's torso.  "+
		"The dog's head rises out of the bronze torso.  Amber gems "+
		"have been used for the dog's eyes.  Long floppy ears droop"+
		" around either side of the dog's head.  A bronze knob juts "+
		"out of the left torso of the dog.  Perhaps you can wind it "+
		"to see what the dog might do.\n");
   	set_name("clockwork dog");
   	set_short("%^RESET%^%^ORANGE%^A clockwork dog%^RESET%^");
     	set_id(({"dog","clockwork dog","clockwork"}));
      break;
   case "pig":
      set_long("%^ORANGE%^Made entirely of bronze this clockwork pig "+
		"is highly detailed.  The body of the pig is shaped from a "+
		"solid piece of bronze, providing stability.  Hollowed bronze"+
		" hoofed feet have been attached internally to the pig's torso."+
		"  The pig's head rises out of the bronze torso.  "+
		"%^BOLD%^%^BLACK%^Jet%^RESET%^%^ORANGE%^ stones have been used "+
		"for the pig's eyes.  A curly tail is attached to the rear of the"+
		" pig.  A bronze knob juts out of the left torso of the pig.  "+
		"Perhaps you can wind it to see what the pig might do.\n");
   	set_name("clockwork pig");
   	set_short("%^RESET%^%^ORANGE%^A clockwork pig%^RESET%^");
     	set_id(({"pig","clockwork pig","clockwork"}));
      break;
   case "cow":
      set_long("%^ORANGE%^Made entirely of bronze this clockwork cow "+
		"is highly detailed.  The body of the cow is shaped from a solid"+
		" piece of bronze, providing stability.  Hollowed bronze hoofed "+
		"feet have been attached internally to the cow's torso.  The cow's"+
		" head rises out of the bronze torso.  %^BOLD%^%^WHITE%^Ivory"+
		"%^RESET%^%^ORANGE%^ has been used for the cow's horns.  A bronze"+
		" knob juts out of the left torso of the cow.  Perhaps you can wind"+
		" it to see what the cow might do.\n");
   	set_name("clockwork cow");
   	set_short("%^RESET%^%^ORANGE%^A clockwork cow%^RESET%^");
     	set_id(({"cow","clockwork cow","clockwork"}));
      break;
   case "squirrel":
      set_long("%^ORANGE%^Made entirely of bronze this clockwork squirrel"+
		" is highly detailed.  The body of the squirrel is shaped from a"+
		" solid piece of bronze, providing stability.  Hollowed bronze "+
		"feet have been attached internally to the squirrel's torso.  "+
		"The squirrel's head rises out of the bronze torso.  Shard of"+
		" %^BOLD%^%^BLACK%^obsidian %^RESET%^%^ORANGE%^have been used"+
		" for the squirrel's eyes.  A bushy metal tail is attached to"+
		" the squirrel's rear.  A bronze knob juts out of the left "+
		"torso of the squirrel.  Perhaps you can wind it to see what"+
		" the squirrel might do.\n");
   	set_name("clockwork squirrel");
   	set_short("%^RESET%^%^ORANGE%^A clockwork squirrel%^RESET%^");
     	set_id(({"squirrel","clockwork squirrel","clockwork"}));
      break;
   case "songbird":
      set_long("%^ORANGE%^Made entirely of bronze this clockwork"+
		" songbird is highly detailed.  The body of the bird is "+
		"shaped from a solid piece of bronze, providing stability."+
		"  Hollowed bronze feet have been attached to internally to"+
		" the bird's torso.  The bird's head rises out of the bronze"+
		" torso.  %^BOLD%^Gold%^RESET%^%^ORANGE%^ leafing has been "+
		"used for the beak of the songbird.  A fanned tail is attached"+
		" to the rear of the bird.  A bronze knob juts out of the left"+
		" torso of the bird.  Perhaps you can wind it to see what the "+
		"songbird might do.\n");
   	set_name("clockwork songbird");
   	set_short("%^RESET%^%^ORANGE%^A clockwork songbird%^RESET%^");
     	set_id(({"songbird","clockwork songbird","clockwork"}));
      break;
   case "orange":
      set_long("%^ORANGE%^Made entirely of bronze this clockwork orange"+
		" is highly detailed.  The round body of the orange is shaped "+
		"from a solid piece of bronze, providing stability.  The surface"+
		" of the orange features small dents, to mimic the texture of a "+
		"real orange.  A slightly flatter bottom allows for the orange to"+
		" rest in one spot without rolling away.  A bronze knob juts out"+
		" of the left side of the orange.  Perhaps you can wind it to see"+
		" what the orange might do.\n");
   	set_name("clockwork orange");
   	set_short("%^RESET%^%^ORANGE%^A clockwork orange%^RESET%^");
     	set_id(({"orange","clockwork orange","clockwork"}));
      break;
   default: set_long("Ack, I'm broken!  Tell Cythera.");
      set_name("broken clock");
      set_short("broken clockwork thing");
      set_id(({"clock","clockwork","thing"}));   
   }
}

void init(){
   ::init();
   add_action("wind","wind");
}

int wind(string str) {
   int i,j;
   object *inven;
   if(!str) {
      notify_fail("Try wind clockwork.");
      return 0;
   }
   if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
   }
   if(str != "clockwork") {
      notify_fail("Try wind clockwork.");
      return 0;
   }
	tell_object(ETO,"%^ORANGE%^You wind the clockwork figurine.");
   if(!random(6)) {
      switch(type){
         case "rabbit": tell_room(EETO,"%^YELLOW%^The rabbit hops about.");
                        break;
         case "cat": tell_room(EETO,"%^YELLOW%^The cat stretches itself"+
                     " out, flicking its tail once.");
                     break;
         case "dog": tell_room(EETO,"%^YELLOW%^The dog wags its tail as"+
                     " it barks once.");
                     break;
         case "pig": tell_room(EETO,"%^YELLOW%^The pig wiggles its snout "+
                     "as it oinks twice.");
                     break;
         case "cow": tell_room(EETO,"%^YELLOW%^The cow lifts its head back "+
                     "and moos twice.");
                     break;
         case "songbird": tell_room(EETO,"%^YELLOW%^The bird bobs its head as it "+
                     "chirps three times.");
                     break;
         case "orange":	tell_room(EETO,"%^YELLOW%^The orange unfolds itself into "+
                     "six equal segments.");
                     break;
         case "squirrel": tell_room(EETO,"%^YELLOW%^The squirrel chatters angrily.");
                     break;
         default: tell_room(EETO,"Ack! I'm broken!");
                  break;
      }
      return 1;
   }
   if(!random(4)){
      switch(type){
         case "rabbit": tell_room(EETO,"%^YELLOW%^The rabbit twitches its nose.");
                        break;
         case "cat": tell_room(EETO,"%^YELLOW%^The cat pounces onto an unseen object.");
                    break;
         case "dog": tell_room(EETO,"%^YELLOW%^The dog sits on the ground and"+
                     " starts to whine.");
                     break;
         case "pig": tell_room(EETO,"%^YELLOW%^The curly tail of the pig wags merrily.");
                     break;
         case "cow": tell_room(EETO,"%^YELLOW%^The cow lowers its head to the "+
                     "ground, mimicking grazing.");
                     break;
         case "songbird": tell_room(EETO,"%^YELLOW%^The bird flaps its wings as it "+
                     "begins to sing a high pitch tune.");
                     break;
         case "orange":	tell_room(EETO,"%^YELLOW%^The orange does nothing.");
                     break;
         case "squirrel": tell_room(EETO,"%^YELLOW%^The squirrel mimics eating something.");
                     break;
         default: tell_room(EETO,"Ack! I'm broken!");
                  break;
      }
      return 1;
   }else{
      switch (type){
         case "rabbit": tell_room(EETO,"%^YELLOW%^The rabbit hops once and"+
                     " then comes to a stop.");
                     break;
         case "cat": tell_room(EETO,"%^YELLOW%^The cat curls up and "+
                     "begins to purr.");
                     break;
         case "dog": tell_room(EETO,"%^YELLOW%^The dog starts to chase"+
                     " its own tail.");
                     break;
         case "pig": tell_room(EETO,"%^YELLOW%^The pig dashes swiftly in"+
                     " a straight line.");
                     break;
         case "cow": tell_room(EETO,"%^YELLOW%^The cow swishes its tail "+
                     "as it walks a couple of steps slowly.");
                     break;
         case "songbird": tell_room(EETO,"%^YELLOW%^The bird hops "+
                     "about as it chirps merrily.");
                     break;
         case "orange":	tell_room(EETO,"%^YELLOW%^The orange starts to roll "+
                     "across the ground.");
                     break;
         case "squirrel": tell_room(EETO,"%^YELLOW%^The squirrel's "+
                     "bushy metal tail dances about");
                     break;
         default: tell_room(EETO,"Ack! I'm broken!");
                  break;
      }
      return 1;
   }
}