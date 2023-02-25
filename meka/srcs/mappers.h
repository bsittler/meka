//-----------------------------------------------------------------------------
// MEKA - mappers.h
// Memory Mapper Emulation - Headers
//-----------------------------------------------------------------------------

#define LOG_READ()      \
   { Msg(MSGT_DEBUG, Msg_Get(MSG_Debug_Trap_Read), CPU_GetPC, Addr); }

#define LOG_WRITE()      \
   { Msg(MSGT_DEBUG, Msg_Get(MSG_Debug_Trap_Write), CPU_GetPC, Value, Addr); }

#ifdef DEBUG_MEM
  void    Write_Error (int Addr, byte Value);
#else
  #define Write_Error(a,v)
#endif

//#define DEBUG_UNINITIALIZED_RAM_ACCESSES

//-----------------------------------------------------------------------------
// Definitions
//-----------------------------------------------------------------------------

#define MAPPER_Auto                             (-1)
#define MAPPER_Standard                         (0)         // Standard Sega mapper.
#define MAPPER_32kRAM                           (1)
#define MAPPER_ColecoVision                     (2)
#define MAPPER_CodeMasters                      (3)
#define MAPPER_93c46                            (4)
#define MAPPER_SG1000                           (5)         // FIXME: Emulating 4KB RAM when it should be 2KB !#@?
#define MAPPER_SMS_ActionReplay                 (6)
#define MAPPER_TVOekaki                         (7)
#define MAPPER_SF7000                           (8)
#define MAPPER_SMS_Korean_A000                  (9)         // Register at 0xA000.
#define MAPPER_SMS_DisplayUnit                  (10)
#define MAPPER_SMS_NoMapper                     (11)        // 0x0000->0xBFFF map to ROM. No mapper register.
#define MAPPER_SMS_Korean_MSX_8KB_0003          (12)        // 8KB bank-switching (4 banks)
#define MAPPER_SMS_Korean_Janggun               (13)        // 8KB bank-switching (4 banks) mixed with 16KB bank-switching
#define MAPPER_SMS_4PakAllAction                (14)
#define MAPPER_SG1000_Taiwan_MSX_Adapter_TypeA  (15)        // 8KB RAM from 0x2000->0x3FFF + regular 2KB ram in 0xC000-0xFFFF range
#define MAPPER_SMS_Korean_FFFF_HiCom            (16)        // Register at 0xFFFF to map 32 KB at 0x0000->0x8000
#define MAPPER_SC3000_Survivors_Multicart       (17)
#define MAPPER_SMS_Korean_MSX_8KB_0300          (18)        // Registers at 0x0000,0x0100,0x0200,0x0300 (Super Multi Game Super 75 in 1, Super Game World 75 etc.)
#define MAPPER_SMS_Korean_2000_xor_1F           (19)        // Register at 0x2000 (128 Hap, Game Mo-eumjip 188 Hap etc.)
#define MAPPER_SMS_Korean_BFFC                  (20)        // Register at 0xBFFC
#define MAPPER_SMS_Korean_FFFE                  (21)        // Register at 0xFFFE (Super Game 45 [Teddy Boy])
#define MAPPER_SMS_Korean_FFF3_FFFC             (22)        // Registers at 0xFFF3 and 0xFFFC (Super Game 150, Super Game 270)
#define MAPPER_SMS_Korean_0000_xor_FF           (23)        // Register at 0x0000 with MSX-oriented paging
#define MAPPER_SMS_Korean_MD_FFF0               (24)        // Registers at 0xFFF0 and 0xFFFF (Mega Mode Super Game 30 [SMS-MD])
#define MAPPER_SMS_Korean_MD_FFF5               (25)        // Registers at 0xFFF5 and 0xFFFF (Jaemiissneun Game Mo-eumjip 42/65 Hap [SMS-MD], Pigu Wang Hap ~ Jaemiiss-neun Game Mo-eumjip [SMS-MD])
#define MAPPER_SMS_Korean_MD_FFFA               (26)        // Registers at 0xFFFA and 0xFFFF (Game Jiphap 30 Hap [SMS-MD])
#define MAPPER_SMS_Korean_MSX_32KB_2000         (27)        // Register at 0x2000 (2 Hap in 1 (Moai-ui bomul, David-2))
#define MAPPER_GG_Super_12_in_1_FFFE            (28)        // Registers at 0xFFFE 0xFFFF (Super 5/7/12 in 1 Game Gear [Mortal Kombat]/[Bare Knuckle 2])
#define MAPPER_GG_Super_GG_15_BFFF_FFFF         (29)        // Registers at 0xBFFF, 0xFFFF, and 0xFFFE (Super GG 15 [Cliffhanger] [Gold & Yellow Label])
#define MAPPER_GG_Turbo_9_in_1_8000_4000        (30)        // Registers at 0x8000 and 0x4000 (Turbo 9 in 1)
#define MAPPER_GG_Gear_20_in_1_FFFF_FFFE_button (31)        // Registers at 0xFFFF and 0xFFFE, reset or pushbutton cycles games (Super Gear 20 in 1 [Ninja Gaiden])
#define MAPPER_GG_FFF8_FFF9_FFFA_FFFE_FFFF      (32)        // Registers at 0xFFF8, 0xFFF9, 0xFFFA, 0xFFFE, and 0xFFFF (Super GG 68 in 1 [Sonic Adventure], GG Super 56 in 1 (B) [Mega Man])
#define MAPPER_GG_Super_73_in_1_FFFE_FFFF       (33)        // Registers at 0xFFFE and 0xFFFF (Super Game Gear 73 in 1 [Sonic 2])
#define MAPPER_GG_Super_73_in_1_8000_4000       (34)        // Registers at 0x8000 and 0x4000 (Super Game Gear 73 in 1 [Street Fighter 2])
#define MAPPER_GG_Super_GG_30_1FFx_FFFx         (35)        // Registers at 0x1FFE, 0xFFFE, 0xFFFF, and 0x1FFF (Super GG 30 [Last Action] [Gold & Green Label], Super GG 15 [Last Action] [Super GG 30 Gold & Green Label])
#define MAPPER_GG_Super_Gear_23_in_1_FFFE_FFFF  (36)        // Registers at 0xFFFE and 0xFFFF (Super Gear 23 in 1 [Ninja Gaiden])
#define MAPPER_GG_Super_GG_18_in_1_FFF8_FFFE    (37)        // Registers at 0xFFF8, 0xFFFE, and 0xFFFF (Super GG 18 in 1 [Nettou Samurai])
#define MAPPER_GG_FFF8_FFF9_FFFA_FFFE_FFFF_15_1 (38)        // Registers at 0xFFF8, 0xFFF9, 0xFFFA, 0xFFFE, and 0xFFFF (Super GG 15 in 1 [Sonic 5], GG Super 68 in 1 [Asterix])
#define MAPPER_SMS_Korean_SMS_32KB_2000         (39)        // Register at 0x2000 (11 Hap Gam-Boy)
#define MAPPER_SMS_Korean_MSX_SMS_8000          (40)        // Register at 0x8000 with 8KB granularity and both MSX and SMS game support (Zemina Best 88)
#define MAPPER_GG_Super_68_in_1_FFFE_FFFF       (41)        // Registers at 0xFFFE and 0xFFFF (Super 68 in 1 [Simpson])
#define MAPPER_GG_Gear_6_in_1_FFFE_FFF7_FFFF    (42)        // Registers at 0xFFFE, 0xFFF7, and 0xFFFF (Gear 6 in 1 [Alien Syndrome])
#define MAPPER_GG_Super_9_in_1_FFFE_FFF7_FFFF   (43)        // Registers at 0xFFFE, 0xFFF7, and 0xFFFF (Super Game Gear 9 in 1 [Sonic II])
#define MAPPER_SMS_Korean_MSX_16KB_BFFE         (44)        // Register at 0xBFFE (Super Game 45 [Road Fighter])
#define MAPPER_SMS_Korean_MSX_16KB_FFFF         (45)        // Register at 0xFFFF (Super Game 30 [Road Fighter] [Super Game 45])
#define MAPPER_SMS_Meta_Power_FFFF_HiCom        (46)        // Power-cycling meta-multicart, inner collections use MAPPER_SMS_Korean_FFFF_HiCom (12 in 1 [Hang On] [SMS-GG], Super 12 in 1 [Teddy Boy] [SMS-MD])
#define MAPPER_SMS_Power_256KB_FFFF_FFFE        (47)        // Power-cycling multicart of 256KB SMS games (Super 2 in 1 - Sonic & Alien Storm [SMS-GG], Untitled 4-in-1 (Moonwalker, Double Dragon, Sagaia & Spider-Man) [SMS-GG])
#define MAPPER_GG_48_in_1_FFF8_FFF9_FFFE_FFFF   (48)        // Registers at 0xFFF8, 0xFFF9, 0xFFFE, 0xFFFF (GG 48 in 1 [Doraemon 2])
#define MAPPER_GG_18_in_1_00xx                  (49)        // Registers at 0x0000..0x001F (18 in 1 - Super Games Collection [Columns])
#define MAPPER_GG_Super_16_in_1_Columns_FFFx    (50)        // Register at 0xFFFx (Game Gear Super 16 in 1 ~ Wudi Xilie [Columns])
#define MAPPER_GG_30_in_1_FFF6_FFFE_FFF7_FFFF   (51)        // Registers at 0xFFF6, 0xFFFE, 0xFFF7, 0xFFFF (Gear 30 in 1 [Sonic])
#define MAPPER_GG_52_in_1_FFF6_FFFE_FFF7_FFFF   (52)        // Registers at 0xFFF6, 0xFFFE, 0xFFF7, 0xFFFF (Gear 52 in 1 [Sonic])
#define MAPPER_GG_Real_24_in_1_FFFE_0000_FFFF   (53)        // Registers at 0xFFFE, 0x0000, 0xFFFF (Real 24 in 1 [Sonic II])
#define MAPPER_GG_Homebrew_FFF2                 (127)       // Register at 0xFFF2 (2404e9ea7e6e520b93a7c24ba49556af01900fd0)

#define READ_FUNC(_NAME)   u8 _NAME(register u16 Addr)
#define WRITE_FUNC(_NAME)  void _NAME(register u16 Addr, register u8 Value)

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

void    Mapper_InitializeLookupTables();
void    Mapper_Get_RAM_Infos(int *plen, int *pstart_addr);
int     Mapper_Autodetect();

// Memory Handler -------------------------------------------------------------
READ_FUNC  (Read_Default);
READ_FUNC  (Read_Mapper_93c46);
READ_FUNC  (Read_Mapper_TVOekaki);
READ_FUNC  (Read_Mapper_SMS_DisplayUnit);
READ_FUNC  (Read_Mapper_SMS_Korean_Janggun);
READ_FUNC  (Read_Mapper_SG1000_Taiwan_MSX_Adapter_TypeA);
//-----------------------------------------------------------------------------
WRITE_FUNC (Write_Default);
WRITE_FUNC (Write_Mapper_SG1000);
WRITE_FUNC (Write_Mapper_32kRAM);
WRITE_FUNC (Write_Mapper_CodeMasters);
WRITE_FUNC (Write_Mapper_93c46);
WRITE_FUNC (Write_Mapper_SMS_ActionReplay);
WRITE_FUNC (Write_Mapper_TVOekaki);
WRITE_FUNC (Write_Mapper_SF7000);
WRITE_FUNC (Write_Mapper_SMS_Korean_A000);
WRITE_FUNC (Write_Mapper_SMS_Korean_BFFC);
WRITE_FUNC (Write_Mapper_SMS_DisplayUnit);
WRITE_FUNC (Write_Mapper_SMS_NoMapper);
WRITE_FUNC (Write_Mapper_SMS_Korean_MSX_8KB_0003);
WRITE_FUNC (Write_Mapper_SMS_Korean_MSX_8KB_0300);
WRITE_FUNC (Write_Mapper_SMS_Korean_Janggun);
WRITE_FUNC (Write_Mapper_SMS_4PakAllAction);
WRITE_FUNC (Write_Mapper_SG1000_Taiwan_MSX_Adapter_TypeA);
WRITE_FUNC (Write_Mapper_SMS_Korean_FFFF_HiCom);
WRITE_FUNC (Write_Mapper_SMS_Korean_2000_xor_1F);
WRITE_FUNC (Write_Mapper_SMS_Korean_FFFE);
WRITE_FUNC (Write_Mapper_SMS_Korean_FFF3_FFFC);
WRITE_FUNC (Write_Mapper_SMS_Korean_0000_xor_FF);
WRITE_FUNC (Write_Mapper_SMS_Korean_MD_FFF0);
WRITE_FUNC (Write_Mapper_SMS_Korean_MD_FFF5);
WRITE_FUNC (Write_Mapper_SMS_Korean_MD_FFFA);
WRITE_FUNC (Write_Mapper_SMS_Korean_MSX_32KB_2000);
WRITE_FUNC (Write_Mapper_GG_Super_12_in_1_FFFE);
WRITE_FUNC (Write_Mapper_GG_Super_GG_15_BFFF_FFFF);
WRITE_FUNC (Write_Mapper_GG_Turbo_9_in_1_8000_4000);
WRITE_FUNC (Write_Mapper_GG_Gear_20_in_1_FFFF_FFFE_button);
WRITE_FUNC (Write_Mapper_GG_FFF8_FFF9_FFFA_FFFE_FFFF);
WRITE_FUNC (Write_Mapper_GG_Super_73_in_1_FFFE_FFFF);
WRITE_FUNC (Write_Mapper_GG_Super_73_in_1_8000_4000);
WRITE_FUNC (Write_Mapper_GG_Super_GG_30_1FFx_FFFx);
WRITE_FUNC (Write_Mapper_GG_Super_Gear_23_in_1_FFFE_FFFF);
WRITE_FUNC (Write_Mapper_GG_Super_GG_18_in_1_FFF8_FFFE);
WRITE_FUNC (Write_Mapper_GG_FFF8_FFF9_FFFA_FFFE_FFFF_15_1);
WRITE_FUNC (Write_Mapper_SMS_Korean_SMS_32KB_2000);
WRITE_FUNC (Write_Mapper_SMS_Korean_MSX_SMS_8000);
WRITE_FUNC (Write_Mapper_GG_Super_68_in_1_FFFE_FFFF);
WRITE_FUNC (Write_Mapper_GG_Gear_6_in_1_FFFE_FFF7_FFFF);
WRITE_FUNC (Write_Mapper_GG_Super_9_in_1_FFFE_FFF7_FFFF);
WRITE_FUNC (Write_Mapper_SMS_Korean_MSX_16KB_BFFE);
WRITE_FUNC (Write_Mapper_SMS_Korean_MSX_16KB_FFFF);
WRITE_FUNC (Write_Mapper_SMS_Meta_Power_FFFF_HiCom);
WRITE_FUNC (Write_Mapper_SMS_Power_256KB_FFFF_FFFE);
WRITE_FUNC (Write_Mapper_GG_48_in_1_FFF8_FFF9_FFFE_FFFF);
WRITE_FUNC (Write_Mapper_GG_18_in_1_00xx);
WRITE_FUNC (Write_Mapper_GG_Super_16_in_1_Columns_FFFx);
WRITE_FUNC (Write_Mapper_GG_30_in_1_FFF6_FFFE_FFF7_FFFF);
WRITE_FUNC (Write_Mapper_GG_52_in_1_FFF6_FFFE_FFF7_FFFF);
WRITE_FUNC (Write_Mapper_GG_Real_24_in_1_FFFE_0000_FFFF);
WRITE_FUNC (Write_Mapper_GG_Homebrew_FFF2);
//-----------------------------------------------------------------------------
void Out_SC3000_SurvivorsMulticarts_DataWrite(u8 v);

extern void Map_8k_RAM    (int page, int ram_page);
extern void Map_8k_ROM    (int page, int rom_page);
extern void Map_8k_Other  (int page, void *);

extern void Map_16k_ROM   (int page, int rom_page);
extern void Map_16k_Other (int page, void *);

//-----------------------------------------------------------------------------

#ifdef DEBUG_UNINITIALIZED_RAM_ACCESSES
extern u8 RAM_IsUninitialized[0x2000];
#endif

//-----------------------------------------------------------------------------
