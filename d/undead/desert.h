#define NORTH       ({ "0,4","0,5","0,6","0,7","0,8","0,9","0,10","1,4","1,5","1,6","1,7","1,8","1,9","1,10","2,4","2,5","2,6","2,7","2,8","2,9","2,10","3,4","3,5","3,6","3,7","3,8","3,9","3,10" })
#define EAST        ({ "4,14","5,14","6,14","7,14","8,14","9,14","10,14","4,13","5,13","6,13","7,13","8,13","9,13","10,13","4,12","5,12","6,12","7,12","8,12","9,12","10,12","4,11","5,11","6,11","7,11","8,11","9,11","10,11" })
#define SOUTH       ({ "14,4","14,5","14,6","14,7","14,8","14,9","14,10","13,4","13,5","13,6","13,7","13,8","13,9","13,10","12,4","12,5","12,6","12,7","12,8","12,9","12,10","11,4","11,5","11,6","11,7","11,8","11,9","11,10" })
#define WEST        ({ "4,0","5,0","6,0","7,0","8,0","9,0","10,0","4,1","5,1","6,1","7,1","8,1","9,1","10,1","4,2","5,2","6,2","7,2","8,2","9,2","10,2","4,3","5,3","6,3","7,3","8,3","9,3","10,3" })
#define NORTHEAST   ({ "0,14","0,13","0,12","0,11","1,14","1,13","1,12","1,11","2,14","2,13","2,12","2,11","3,14","3,13","3,12","3,11" })
#define SOUTHEAST   ({ "14,14","14,13","14,12","14,11","13,14","13,13","13,12","13,11","12,14","12,13","12,12","12,11","11,14","11,13","11,12","11,11" })
#define SOUTHWEST   ({ "14,0","14,1","14,2","14,3","13,0","13,1","13,2","13,3","12,0","12,1","12,2","12,3","11,0","11,1","11,2","11,3" })
#define NORTHWEST   ({ "0,0","0,1","0,2","0,3","1,0","1,1","1,2","1,3","2,0","2,1","2,2","2,3","3,0","3,1","3,2","3,3" })
#define MIDDLE      NORTH + EAST + SOUTH + WEST + NORTHEAST + SOUTHEAST + SOUTHWEST + NORTHWEST

#define S_N         "%^YELLOW%^You are in the northern part of the desert.%^RESET%^"
#define S_E         "%^YELLOW%^You are in the eastern part of the desert.%^RESET%^"
#define S_S         "%^YELLOW%^You are in the southern part of the desert.%^RESET%^"
#define S_W         "%^YELLOW%^You are in the western part of the desert.%^RESET%^"
#define S_NE        "%^YELLOW%^You are in the northeastern part of the desert.%^RESET%^"
#define S_SE        "%^YELLOW%^You are in the southeastern part of the desert.%^RESET%^"
#define S_SW        "%^YELLOW%^You are in the southwestern part of the desert.%^RESET%^"
#define S_NW        "%^YELLOW%^You are in the northwestern part of the desert.%^RESET%^"
#define S_MID       "%^YELLOW%^You are in the middle of a vast desert.%^RESET%^"

#define N_DESC      "A mountain range blocks your movement to the north.  Sand and desert are everywhere else."
#define E_DESC      "There is a great sea to the east of here.  Sand and desert are everywhere else."
#define S_DESC      "There is the ocean to the south blocking any movement in that direction.  Sand and desert are everywhere else."
#define W_DESC      "There is a large flowing river to the west.  Sand and desert are everywhere else."
#define NE_DESC     "There is a great sea to the east of here, mountains to the north.  Sand and desert are everywhere else."
#define SE_DESC     "There is nothing but ocean to your east and to your south.  Sand and desert are everywhere else."
#define SW_DESC     "There is a vast ocean to the south and a raging river to the west.  Sand and desert are everywhere else."
#define NW_DESC     "There are mountains to the west, mountains to the north.  Sand and desert are everywhere else." 
#define MID_DESC    "There is nothing but sand all around for as far as the eye can see."

#define SM_N        "You can smell the crisp scent of the mountain air as it wafts in from the north."
#define SM_E        "You can smell the warm, salty scent of the sea to the east."
#define SM_S        "You can smell the powerful scent of the ocean to the south."
#define SM_W        "You can smell the fishy scent of the rapidly running river to the west."
#define SM_NE       "The scent of the sea mingles with the cool breeze from the mountain to the north."
#define SM_SE       "You can smell the powerful scent of the ocean to the south and east."
#define SM_SW       "The scent of the ocean to the south mingles with the river to the west."
#define SM_NW       "The scent of the mountains to the north and west fills the air here."
#define SM_MID      "The dry air is parched, you can smell little other than the stale odor of dusty bones."

#define SO_N        "You can hear an occasional cry from a bird circling above the mountains to the north."
#define SO_E        "You can hear the sound of the waves from the sea to the east."
#define SO_S        "The crashing roar of the ocean waves makes it way to you from the south."
#define SO_W        "You can hear the sound of a roaring river to the west."
#define SO_NE       "The sounds of the sea to the east and the call of birds from the mountains to the north fill your ears."
#define SO_SE       "The relaxing drone of the ocean waves to the south and east make it to your ears."
#define SO_SW       "You can hear as the raging river slows and plunges into the ocean to the south."
#define SO_NW       "You can hear an occasional cry from a bird circling above the mountains to the north and west."
#define SO_MID      "The sound of a dry desert wind whips past your ears, carrying with it the occasional inhuman scream."
