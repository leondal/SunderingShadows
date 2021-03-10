#include <std.h>

inherit OBJECT;

void create()
{
	::create();	
	set_name("guardian's orb");
	set_value(5);
	set_weight(2);
}

void set_my_key_type(int KeyNum)
{
	string MyColor, MyKeyName;
	switch(KeyNum)
	{
		case 1:
			MyColor = "%^RESET%^%^BLUE%^";
			MyKeyName = "blue_guardian_orb_saide";
			break;
		case 2:
			MyColor = "%^BOLD%^%^GREEN%^";
			MyKeyName = "green_guardian_orb_saide";
			break;
		case 3:
			MyColor = "%^BOLD%^%^MAGENTA%^";
			MyKeyName = "magenta_guardian_orb_saide";
			break;
		case 4:
			MyColor = "%^BOLD%^%^BLACK%^";
			MyKeyName = "black_guardian_orb_saide";
			break;
	}

	set_id(({"orb", "guardian orb", MyKeyName}));
	set_short("%^BOLD%^%^WHITE%^A flawless %^RESET%^"+MyColor+
	"orb%^RESET%^");

	set_long("%^BOLD%^%^WHITE%^This small %^RESET%^"+MyColor+
	"orb%^BOLD%^%^WHITE%^ is only a couple of "+
	"inches in diamater.  It is circular in form and absolutely "+
	"flawless.  It is covered in %^BOLD%^%^BLACK%^ancient"+
	"%^BOLD%^%^WHITE%^ tiny markings each one etched in "+
	"%^RESET%^"+MyColor+"perfect detail%^BOLD%^%^WHITE%^.  "+
	"It gives off a potent %^RESET%^"+MyColor+"aura%^BOLD%^"+
	"%^WHITE%^ of magic.%^RESET%^");
	return;	
}

void isMagic()
{
	::isMagic();
	return 4;
}

