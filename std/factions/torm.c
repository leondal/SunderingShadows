// settings for the faction system: Torm (Thorm), human city.

string query_blurb() { // brief summary of the faction & its details
    return "Torm, or Thorm as it was known of old, is a major human city located on the coast of the Dagger "
"Sea. Once the capital of a great Aesatri kingdom of the same name, it was known as the Heart of the North, a "
"city of broad influence and uncommonly upstanding principles. Its power has dwindled over the centuries, "
"culminating in the fall of the royal line in the early 600's SG. This was later revealed to have been caused "
"by the machinations of the Maskarran church, and a group of adventurers succeeded in restoring the long-hidden "
"heirs to the throne in 724SG. They are now left with the daunting task of trying to restore the fallen kingdom "
"to its former glory, despite their once-subject city-state Tonovi placing constant pressure upon their northern "
"border...";
}

string query_race() { return "human"; } // primary racial stock of the faction
string query_alignment() { return "neutral good"; } // base alignment of the faction
string query_location() { return "in the Dagger region, located on the coastline"; } // location of the faction
int query_tangible() { return 1; } // 1 if faction is part of the coded game (eg/ city); 0 if off-screen plot faction

// start ratings - should span from friendly thru indifferent to unfriendly or hostile.
// 300 for friendly (eg/ elves in an elven city); 0 for indifferent (eg/ halflings in an elven city);
// -300 for unfriendly (eg/ dwarf in an elven city); -600 for hostile (eg/ drow in an elven city)
int query_start_attitude(object theplayer) {
    string myrace,mysubrace,myshapeshift;
    if(!objectp(theplayer)) return 0;

    myrace = (string)theplayer->query_race();
    mysubrace = (string)theplayer->query("subrace");
    myshapeshift = (string)theplayer->query("relationship_profile");

// first let's deal with beasties!
    switch(myshapeshift) {
      case "druid_dragon_999": case "druid_elemental_999": return -600;
      case "druid_bird_999": case "druid_cat_999": case "druid_wolf_999": case "yuan-ti_viper_999": return -300;
    }

// now let's deal with non-shifted!
    switch(myrace) { // non-break switch, fall-thru if no match is needed for subraces
      case "bugbear": case "drow": case "gnoll": case "goblin": case "half-drow": case "half-ogre":
      case "hobgoblin": case "kobold": case "minotaur": case "orc": case "ogre": case "ogre-mage":
      case "yuan-ti":
        return -600;
      case "dwarf": if(mysubrace == "gray dwarf" || mysubrace == "duergar") return -600;
      case "elf": if(mysubrace == "fey'ri" && !theplayer->query_property("altered")) return -600; // undisguised fey'ri
      default: return 0;
    }
}