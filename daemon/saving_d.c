//ACTIVELY USED BY A FEW MOBS
//Should be phased out

// saving throw daemon
// mindlessly processed

int return_throw(string save, string myclass, int level) {
  if(myclass == "assassin") myclass = "thief";
  if(myclass == "antipaladin" || myclass == "cavalier") myclass = "paladin";
  if(save == "paralyzation_poison_death") {
    if((myclass == "cleric") || (myclass == "psywarrior")) {
      switch(level) {
      case 1..3 : return 10; break;
      case 4..6 : return 9; break;
      case 7..9 : return 7; break;
      case 10..12 : return 6; break;
      case 13..15 : return 5; break;
      case 16..18 : return 4; break;
      default : return 10 - (level/3 +1); break;
      }
    }
    if((myclass == "thief") || (myclass == "bard")) {
      switch(level) {
      case 1..4 : return 13; break;
      case 5..8 : return 12; break;
      case 9..12 : return 11; break;
      case 13..16 : return 10; break;
      case 17..20 : return 9; break;
      default : return 13- (level/4)+1; break;
      }
    }
    if((myclass == "fighter") || (myclass == "ranger")) {
      switch(level) {
      case 0 : return 16; break;
      case 1..2 : return 14; break;
      case 3..4 : return 13; break;
      case 5..6 : return 11; break;
      case 7..8 : return 10; break;
      case 9..10 : return 8; break;
      case 11..12 : return 7; break;
      case 13..14 : return 5; break;
      case 15..16 : return 4; break;
      default : return 12 - (level/2)+1; break;
      }
    }
    if((myclass == "paladin")||(myclass == "antipaladin")||(myclass == "cavalier")) {
      switch(level) {
      case 0 : return 14; break;
      case 1..2 : return 12; break;
      case 3..4 : return 11; break;
      case 5..6 : return 9; break;
      case 7..8 : return 8; break;
      case 9..10 : return 6; break;
      case 11..12 : return 5; break;
      case 13..14 : return 3; break;
      case 15..16 : return 2; break;
      default : return 10- ( level/2)+1; break;
      }
    }
    if((myclass == "mage") || (myclass == "psion") || (myclass == "sorcerer") || (myclass == "warlock")) {
      switch(level) {
      case 1..5 : return 14; break;
      case 6..10 : return 13; break;
      case 11..15 : return 11; break;
      case 16..20 : return 10; break;
      default : return 12- (level/4)+1; break;
      }
    }
  }
  if(save == "rod_staff_wand") {
    if((myclass == "cleric") || (myclass == "psywarrior")) {
      switch(level) {
      case 1..3 : return 14; break;
      case 4..6 : return 13; break;
      case 7..9 : return 11; break;
      case 10..12 : return 10; break;
      case 13..15 : return 9; break;
      case 16..18 : return 8; break;
      default : return 9 - (level/3 +1); break;
      }
    }
    if((myclass == "thief") || (myclass == "bard")) {
      switch(level) {
      case 1..4 : return 14; break;
      case 5..8 : return 12; break;
      case 9..12 : return 10; break;
      case 13..16 : return 8; break;
      case 17..20 : return 6; break;
      default : return 8- (level/4)+1; break;
      }
    }
    if((myclass == "fighter") || (myclass == "ranger") || (myclass == "paladin")|| (myclass == "antipaladin")|| (myclass == "cavalier"))
      {
	switch(level) {
        case 0 : return 18; break;
        case 1..2 : return 16; break;
        case 3..4 : return 15; break;
        case 5..6 : return 13; break;
        case 7..8 : return 12; break;
        case 9..10 : return 10; break;
        case 11..12 : return 9; break;
        case 13..14 : return 7; break;
        case 15..16 : return 6; break;
        default : return 16- ( level/2)+1; break;
	}
      }
    if((myclass == "mage") || (myclass == "psion") || (myclass == "sorcerer") || (myclass == "warlock")) {
      switch(level) {
      case 1..5 : return 11; break;
      case 6..10 : return 9; break;
      case 11..15 : return 7; break;
      case 16..20 : return 5; break;
      default : return 10- ( level/4)+1; break;
      }
    }
  }
  if(save == "petrification_polymorph") {
    if((myclass == "cleric") || (myclass == "psywarrior")) {
      switch(level) {
      case 1..3 : return 13; break;
      case 4..6 : return 12; break;
      case 7..9 : return 10; break;
      case 10..12 : return 9; break;
      case 13..15 : return 8; break;
      case 16..18 : return 7; break;
      default : return 13- ( level/3)+1; break;
      }
    }
    if((myclass == "thief") || (myclass == "bard")) {
      switch(level) {
      case 1..4 : return 12; break;
      case 5..8 : return 11; break;
      case 9..12 : return 10; break;
      case 13..16 : return 9; break;
      case 17..20 : return 8; break;
      default : return 13- ( level/4)+1; break;
      }
    }
    if((myclass == "fighter") || (myclass == "ranger") || (myclass == "paladin"))
      {
	switch(level) {
        case 0 : return 17; break;
        case 1..2 : return 15; break;
        case 3..4 : return 14; break;
        case 5..6 : return 12; break;
        case 7..8 : return 11; break;
        case 9..10 : return 9; break;
        case 11..12 : return 8; break;
        case 13..14 : return 6; break;
        case 15..16 : return 5; break;
        default : return 13- ( level/2)+1; break;
	}
      }
    if((myclass == "mage") || (myclass == "psion") || (myclass == "sorcerer") || (myclass == "warlock")) {
      switch(level) {
      case 1..5 : return 13; break;
      case 6..10 : return 11; break;
      case 11..15 : return 9; break;
      case 16..20 : return 7; break;
      default : return 10- ( level/5)+1; break;
      }
    }
  }
  if(save == "breath_weapon") {
    if((myclass == "cleric") || (myclass == "psywarrior")) {
      switch(level) {
      case 1..3 : return 16; break;
      case 4..6 : return 15; break;
      case 7..9 : return 13; break;
      case 10..12 : return 12; break;
      case 13..15 : return 11; break;
      case 16..18 : return 10; break;
      default : return 13- ( level/4)+1; break;
      }
    }
    if((myclass == "thief") || (myclass == "bard")) {
      switch(level) {
      case 1..4 : return 16; break;
      case 5..8 : return 15; break;
      case 9..12 : return 14; break;
      case 13..16 : return 13; break;
      case 17..20 : return 12; break;
      default : return 17- ( level/4)+1; break;
      }
    }
    if((myclass == "fighter") || (myclass == "ranger") || (myclass == "paladin")|| (myclass == "antipaladin")|| (myclass == "cavalier"))
      {
	switch(level) {
        case 0 : return 20; break;
        case 1..2 : return 17; break;
        case 3..4 : return 16; break;
        case 5..6 : return 13; break;
        case 7..8 : return 12; break;
        case 9..10 : return 9; break;
        case 11..12 : return 8; break;
        case 13..14 : return 5; break;
        case 15..16 : return 4; break;
        default : return 12- ( level/2)+1; break;
	}
      }
    if((myclass == "mage") || (myclass == "psion") || (myclass == "sorcerer") || (myclass == "warlock")) {
      switch(level) {
      case 1..5 : return 15; break;
      case 6..10 : return 13; break;
      case 11..15 : return 11; break;
      case 16..20 : return 9; break;
      default : return 12- ( level/5)+1; break;
      }
    }
  }
  if ((save == "spell") || (save == "spells")) {
    if((myclass == "cleric") || (myclass == "psywarrior")) {
      switch(level) {
      case 1..3 : return 15; break;
      case 4..6 : return 14; break;
      case 7..9 : return 12; break;
      case 10..12 : return 11; break;
      case 13..15 : return 10; break;
      case 16..18 : return 9; break;
      default : return 13- ( level/4)+1; break;
      }
    }
    if((myclass == "thief") || (myclass == "bard")) {
      switch(level) {
      case 1..4 : return 15; break;
      case 5..8 : return 13; break;
      case 9..12 : return 11; break;
      case 13..16 : return 9; break;
      case 17..20 : return 7; break;
      default : return 11- ( level/4)+1; break;
      }
    }
    if((myclass == "fighter") || (myclass == "ranger") || (myclass == "paladin")|| (myclass == "antipaladin")|| (myclass == "cavalier"))
      {
	switch(level) {
        case 0 : return 19; break;
        case 1..2 : return 17; break;
        case 3..4 : return 16; break;
        case 5..6 : return 14; break;
        case 7..8 : return 13; break;
        case 9..10 : return 11; break;
        case 11..12 : return 10; break;
        case 13..14 : return 8; break;
        case 15..16 : return 7; break;
        default : return 16- ( level/2)+1; break;
	}
      }
    if((myclass == "mage") || (myclass == "psion") || (myclass == "sorcerer") || (myclass == "warlock")) {
      switch(level) {
      case 1..5 : return 12; break;
      case 6..10 : return 10; break;
      case 11..15 : return 8; break;
      case 16..20 : return 6; break;
      default : return 10- ( level/5)+1; break;
      }
    }
  }
  return 20;  // not a valid type!  ack!
}

int get_saving_throw(object tp, string save) {
  string myclass, *classes;
  int level;
  int x,j,i,tmp;
  
  tmp = 20;
  if(!objectp(tp)) return 0;

  if(tp->is_class("warlord")) // temporary
  {
    if( j = sizeof(classes = (string *)tp->query_classes()) ) {
      for(x = 0; x < j; x++) {
        myclass = classes[x];   // class = the class string of x
        level = tp->query_class_level(myclass);
        i = return_throw(save, (string)"/std/class/warlord.c"->old_save_type(), level);
        if(i < tmp) tmp = i;
      } // For loop
    }  // if multiclassed
    else
      {
	if(!myclass = tp->query_class())
          myclass="fighter";
	if(!level = tp->query_level())
          level=1;
	tmp = return_throw(save, myclass, level);
      }
    tmp = tmp +(-(int) (tp->query_saving_bonus(save)));
    return tmp;
  }

  else if(interactive(tp)) {
    if( j = sizeof(classes = (string *)tp->query_classes()) ) {
      for(x = 0; x < j; x++) {
        myclass = classes[x];   // class = the class string of x
        level = tp->query_class_level(myclass);
        i = return_throw(save, myclass, level);
        if(i < tmp) tmp = i;
      } // For loop
    }  // if multiclassed
    else
      {
	if(!myclass = tp->query_class())
          myclass="fighter";
	if(!level = tp->query_level())
          level=1;
	tmp = return_throw(save, myclass, level);
      }
    tmp = tmp +(-(int) (tp->query_saving_bonus(save)));
    return tmp;
  }
  else
    {
      myclass = tp->query_class();
      level = tp->query_hd();
      tmp = return_throw(save, myclass, level);
      tmp = tmp +(-(int) (tp->query_saving_bonus(save)));
      return tmp;
    }
}

int saving_throw(object tp, string save, int change)
{
    int rolled;
    rolled = random(20) + 1; // Count from 0...
    if(rolled == 20) return 1;
    if(rolled == 1) return 0;
    rolled += change;
    if(rolled >= get_saving_throw(tp, save)) return 1;
    return 0;
}
