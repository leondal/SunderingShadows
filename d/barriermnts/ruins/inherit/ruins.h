#include <std.h>

#define ROOMS "/d/barriermnts/ruins/room/"
#define MON "/d/barriermnts/ruins/mon/"
#define OBJ "/d/barriermnts/ruins/obj/"
#define BASE "/d/barriermnts/ruins/inherit/"

#define CRYSTALMSG ({"%^CYAN%^The %^BOLD%^crystal ball%^RESET%^%^CYAN%^ glows brighter, drawing your gaze into its depths as images begin to form before your eyes. You find yourself unable to look away.%^RESET%^",\
  "%^WHITE%^%^BOLD%^A young, %^YELLOW%^blonde%^WHITE%^ haired human magus stands among ruins in some unknown location.  He is obviously searching for something.%^RESET%^",\
  "%^WHITE%^%^BOLD%^He stops suddenly, and a curious expression crosses his features as he bends down to pick up an %^BLUE%^amulet%^WHITE%^ from beneath a pile of rubble.%^RESET%^",\
  "%^WHITE%^%^BOLD%^His hand closes around the amulet...%^RESET%^",\
  "%^WHITE%^%^BOLD%^The mage's eyes widen, as his lips part in a silent scream... and then his eyes take on a dull sheen, as he reaches up and clasps the amulet around his neck.%^RESET%^",\
  "%^WHITE%^%^BOLD%^The scene fades, and another appears in its wake - the same magus, with the amulet around his neck, kneeling at the bedside of a sick child.%^RESET%^",\
  "%^WHITE%^%^BOLD%^He touches his hands to her forehead, murmuring as the %^BLUE%^amulet%^WHITE%^ at his throat glows briefly.%^RESET%^",\
  "%^WHITE%^%^BOLD%^The child opens her eyes, the pallor fading from her face as she sits up from the bed, perfectly healed.%^RESET%^",\
  "%^WHITE%^%^BOLD%^The image becomes %^BLACK%^hazy%^WHITE%^, and another forms, of a large stone-walled room with a mosaic-tiled roof.%^RESET%^",\
  "%^WHITE%^%^BOLD%^The magus stands before a small gathering of others, all garbed in similar formal clothing.%^RESET%^",\
  "%^WHITE%^%^BOLD%^You can hear his voice as he speaks, %^RESET%^%^GREEN%^'Join with me! Follow the True Voice and it will lead you out of this nothingness!'%^RESET%^",\
  "%^WHITE%^%^BOLD%^His words are met with cheers and approval, fading from your ears as the scene becomes cloudy.%^RESET%^",\
  "%^WHITE%^%^BOLD%^The vision clears, showing the room around you, and the magus who steps into the %^CYAN%^mirror%^WHITE%^ and reappears in a room behind it.%^RESET%^",\
  "%^WHITE%^%^BOLD%^He shudders and falls to his knees, as a disembodied voice rasps %^RED%^'More, Archemond... give me their lives!'%^RESET%^",\
  "%^WHITE%^%^BOLD%^The vision fades, revealing another: %^WHITE%^%^BOLD%^an ornately-decorated cathedral and a %^RESET%^%^RED%^blood-stained%^WHITE%^%^BOLD%^ altar, upon which is tied a young woman, her eyes glazed over.%^RESET%^",\
  "%^WHITE%^%^BOLD%^Behind the altar, the magus Archemond raises a wicked three-bladed weapon above his head.%^RESET%^",\
  "%^WHITE%^%^BOLD%^He yells out to those gathered %^RESET%^%^GREEN%^'Now, give your life to the True Voice, and become one with it!'%^WHITE%^%^BOLD%^, bringing down the weapon upon the captive woman.%^RESET%^",\
  "%^WHITE%^%^BOLD%^A last sigh of life escapes her lips, as the %^BLUE%^amulet%^WHITE%^ at Archemond's throat flares with %^YELLOW%^light%^WHITE%^.%^RESET%^",\
})
