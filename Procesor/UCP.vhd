----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:42:44 05/04/2018 
-- Design Name: 
-- Module Name:    UCP - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
LIBRARY ieee;
library work ;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL; 
use ieee.std_logic_textio.all;
--use work.functions.all ;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity UCP is
    Port ( Bus_address : out  STD_LOGIC_VECTOR (7 downto 0); -- bus reserved for sending adresses 
           Bus_control : out  STD_LOGIC_VECTOR (1 downto 0);           -- bus reserved for selecting Memory Write/Read , IO write/Read
			  Bus_data : inout  STD_LOGIC_VECTOR (15 downto 0);  -- bus reserved for sending and receiving data acording to RC
			  Clk : in std_logic ;-- clk to all main 
			  Interuptions : in std_logic  -- could be a vector so we say how many there are
			  --add a new "bus" to communicate between UAL and RA
			  );
end UCP;

architecture Behavioral of UCP is
signal Data :std_logic_vector(15 downto 0);    -- result from UAL to data
signal data_address :std_logic_vector(15 downto 0);

signal reg_curr_instr : std_logic_vector (31 downto 0);  -- to be debated how we structure our instructions

signal curr_op: std_logic_vector(7 downto 0);
signal flag : std_logic_vector(3 downto 0);
signal result : STD_LOGIC_VECTOR (15 downto 0);



--signal Reset : std_logic := '0' ;
--signal cpu_data_di: std_logic_vector (31 downto 0);
--signal cpu_data_do: std_logic_vector (31 downto 0);
--signal cpu_data_we : std_logic ;


signal status : integer range 0 to 10; -- we can have a lvl 10 only status of each instr


type register_array is array(0 to 512) of STD_LOGIC_VECTOR (31 downto 0); -- check for a way to put  variables 
signal instr_mem: register_array;

type reg_type is array (15 downto 0) of std_logic_vector(15 downto 0);-- our registries
signal reg : reg_type:= (others => x"0000");


type reg_rec_type is array (10 downto 0) of std_logic_vector(15 downto 0);-- our registries
signal reg_recursivity : reg_rec_type ; -- could create another type of recusivity


--counting all instructions to be able to return and advance
signal currentInst : integer range 0 to 1024; -- make it better
signal currentRecursivityLevel : integer range 0 to 10 ;

signal regSelectorA:std_logic_vector(15 downto 0);
signal regSelectorB:std_logic_vector(15 downto 0);

signal signalStore : std_logic_vector(15 downto 0);


component UAL	
    Port(  A : in  STD_LOGIC_VECTOR (15 downto 0);
           B : in  STD_LOGIC_VECTOR (15 downto 0);
           Op : in  STD_LOGIC_VECTOR (7 downto 0);
           S : out  STD_LOGIC_VECTOR (15 downto 0);
           Flag : out  STD_LOGIC_VECTOR (3 downto 0) ); -- enable output of the data 
end component;

component bram32
  generic (
    init_file : String := "hex_instr.hex";
    adr_width : Integer := 12);
  port (
	  -- System
	  sys_clk : in std_logic;
	  sys_rst : in std_logic;
	  -- Master
	  di : out std_logic_vector(31 downto 0);
	  we : in std_logic;
	  a : in std_logic_vector(15 downto 0);
	  do : in std_logic_vector(31 downto 0));
end component;


begin

--memory_test : bram32 port map (
--									sys_clk => Clk,
--									sys_rst => Reset,
--									di => cpu_data_di,
--									do => cpu_data_do,
--									a => std_logic_vector(to_unsigned(currentInst, 16)),
--									we => cpu_data_we );


ALU:UAL port map(regSelectorA,regSelectorB,curr_op,result,flag); -- we always put the resultat S in r1
            --  op @1 @2/
--####### How to use the instructions ######
--	Format: [Op][Op]AABBBB (first 2 operations; next 2 A, last 4 B.
--	Ops: |00 |01 |02 |03 |   04  05   06  07 08   09  0A   0B  0C  0D    0E  0F
--		  |ADD|SUB|MUL|DIV|STORE LOAD AFC EQU INF InfE Sup SupE Jmp Jmpc Call Ret


instr_mem(0)<=x"06010004" ;
instr_mem(1)<=x"060e0000" ;
instr_mem(2)<=x"000e000f" ;
instr_mem(3)<=x"040e0001" ;
instr_mem(5)<=x"060e0001" ;
instr_mem(6)<=x"000e000f" ;
instr_mem(7)<=x"0501000e" ;
instr_mem(8)<=x"060e0005" ;
instr_mem(9)<=x"000e000f" ;
instr_mem(10)<=x"040e0001" ;
instr_mem(11)<=x"060e0005" ;
instr_mem(12)<=x"000e000f" ;
instr_mem(13)<=x"0501000e" ;
instr_mem(14)<=x"060e0003" ;
instr_mem(15)<=x"000e000f" ;
instr_mem(16)<=x"040e0001" ;
instr_mem(17)<=x"060e0002" ;
instr_mem(18)<=x"000e000f" ;
instr_mem(19)<=x"0501000e" ;
instr_mem(20)<=x"060e0005" ;
instr_mem(21)<=x"000e000f" ;
instr_mem(22)<=x"040e0001" ;
instr_mem(23)<=x"060e0005" ;
instr_mem(24)<=x"000e000f" ;
instr_mem(25)<=x"0501000e" ;
instr_mem(26)<=x"060e0004" ;
instr_mem(27)<=x"000e000f" ;
instr_mem(28)<=x"040e0001" ;
instr_mem(29)<=x"060e0003" ;
instr_mem(30)<=x"000e000f" ;
instr_mem(31)<=x"0501000e" ;
instr_mem(32)<=x"060e0005" ;
instr_mem(33)<=x"000e000f" ;
instr_mem(34)<=x"040e0001" ;
instr_mem(35)<=x"060e0004" ;
instr_mem(36)<=x"000e000f" ;
instr_mem(37)<=x"0501000e" ;
instr_mem(38)<=x"060e0006" ;
instr_mem(39)<=x"000e000f" ;
instr_mem(40)<=x"040e0001" ;
instr_mem(41)<=x"060e0006" ;
instr_mem(42)<=x"000e000f" ;
instr_mem(43)<=x"0501000e" ;
instr_mem(44)<=x"060e0005" ;
instr_mem(45)<=x"000e000f" ;
instr_mem(46)<=x"0502000e" ;
instr_mem(47)<=x"07020001" ;
instr_mem(48)<=x"060e0005" ;
instr_mem(49)<=x"000e000f" ;
instr_mem(50)<=x"040e0002" ;
instr_mem(51)<=x"060e0005" ;
instr_mem(52)<=x"000e000f" ;
instr_mem(53)<=x"050a000e" ;
instr_mem(54)<=x"0c3e000a" ;
instr_mem(55)<=x"060e0003" ;
instr_mem(56)<=x"000e000f" ;
instr_mem(57)<=x"0501000e" ;
instr_mem(58)<=x"060e0001" ;
instr_mem(59)<=x"000e000f" ;
instr_mem(60)<=x"040e0001" ;
instr_mem(61)<=x"0e010001" ;
instr_mem(63)<=x"060e0004" ;
instr_mem(64)<=x"000e000f" ;
instr_mem(65)<=x"0501000e" ;
instr_mem(66)<=x"060e0001" ;
instr_mem(67)<=x"000e000f" ;
instr_mem(68)<=x"040e0001" ;
instr_mem(69)<=x"0e010001" ;
instr_mem(70)<=x"0601000a" ;
instr_mem(71)<=x"060e0005" ;
instr_mem(72)<=x"000e000f" ;
instr_mem(73)<=x"040e0001" ;
instr_mem(74)<=x"06010005" ;
instr_mem(75)<=x"060e0007" ;
instr_mem(76)<=x"000e000f" ;
instr_mem(77)<=x"040e0001" ;
instr_mem(78)<=x"06010001" ;
instr_mem(79)<=x"060e0009" ;
instr_mem(80)<=x"000e000f" ;
instr_mem(81)<=x"040e0001" ;
instr_mem(82)<=x"06010000" ;
instr_mem(83)<=x"060e000a" ;
instr_mem(84)<=x"000e000f" ;
instr_mem(85)<=x"040e0001" ;
instr_mem(86)<=x"06010000" ;
instr_mem(87)<=x"060e000b" ;
instr_mem(88)<=x"000e000f" ;
instr_mem(89)<=x"040e0001" ;
instr_mem(90)<=x"060e0005" ;
instr_mem(91)<=x"000e000f" ;
instr_mem(92)<=x"0501000e" ;
instr_mem(93)<=x"060e0010" ;
instr_mem(94)<=x"000e000f" ;
instr_mem(95)<=x"040e0001" ;
instr_mem(96)<=x"06010016" ;
instr_mem(97)<=x"060e0011" ;
instr_mem(98)<=x"000e000f" ;
instr_mem(99)<=x"040e0001" ;
instr_mem(100)<=x"060e0011" ;
instr_mem(101)<=x"000e000f" ;
instr_mem(102)<=x"0501000e" ;
instr_mem(103)<=x"060e0010" ;
instr_mem(104)<=x"000e000f" ;
instr_mem(105)<=x"0502000e" ;
instr_mem(106)<=x"07020001" ;
instr_mem(107)<=x"060e0010" ;
instr_mem(108)<=x"000e000f" ;
instr_mem(109)<=x"040e0002" ;
instr_mem(110)<=x"060e0010" ;
instr_mem(111)<=x"000e000f" ;
instr_mem(112)<=x"050a000e" ;
instr_mem(113)<=x"0c9f000a" ;
instr_mem(114)<=x"060e0006" ;
instr_mem(115)<=x"000e000f" ;
instr_mem(116)<=x"0501000e" ;
instr_mem(117)<=x"060e0010" ;
instr_mem(118)<=x"000e000f" ;
instr_mem(119)<=x"040e0001" ;
instr_mem(120)<=x"06010001" ;
instr_mem(121)<=x"060e0011" ;
instr_mem(122)<=x"000e000f" ;
instr_mem(123)<=x"040e0001" ;
instr_mem(124)<=x"060e0011" ;
instr_mem(125)<=x"000e000f" ;
instr_mem(126)<=x"0501000e" ;
instr_mem(127)<=x"060e0010" ;
instr_mem(128)<=x"000e000f" ;
instr_mem(129)<=x"0502000e" ;
instr_mem(130)<=x"07020001" ;
instr_mem(131)<=x"060e0010" ;
instr_mem(132)<=x"000e000f" ;
instr_mem(133)<=x"040e0002" ;
instr_mem(134)<=x"060e0010" ;
instr_mem(135)<=x"000e000f" ;
instr_mem(136)<=x"050a000e" ;
instr_mem(137)<=x"0c94000a" ;
instr_mem(138)<=x"0601000a" ;
instr_mem(139)<=x"060e0010" ;
instr_mem(140)<=x"000e000f" ;
instr_mem(141)<=x"040e0001" ;
instr_mem(142)<=x"060e0010" ;
instr_mem(143)<=x"000e000f" ;
instr_mem(144)<=x"0501000e" ;
instr_mem(145)<=x"060e0008" ;
instr_mem(146)<=x"000e000f" ;
instr_mem(147)<=x"040e0001" ;
instr_mem(149)<=x"06010002" ;
instr_mem(150)<=x"060e0010" ;
instr_mem(151)<=x"000e000f" ;
instr_mem(152)<=x"040e0001" ;
instr_mem(153)<=x"060e0010" ;
instr_mem(154)<=x"000e000f" ;
instr_mem(155)<=x"0501000e" ;
instr_mem(156)<=x"060e0008" ;
instr_mem(157)<=x"000e000f" ;
instr_mem(158)<=x"040e0001" ;
instr_mem(160)<=x"06010000" ;
instr_mem(161)<=x"060e0010" ;
instr_mem(162)<=x"000e000f" ;
instr_mem(163)<=x"040e0001" ;
instr_mem(164)<=x"060e0010" ;
instr_mem(165)<=x"000e000f" ;
instr_mem(166)<=x"0501000e" ;
instr_mem(167)<=x"060e0008" ;
instr_mem(168)<=x"000e000f" ;
instr_mem(169)<=x"040e0001" ;
instr_mem(170)<=x"060e0008" ;
instr_mem(171)<=x"000e000f" ;
instr_mem(172)<=x"0501000e" ;
instr_mem(173)<=x"060e0010" ;
instr_mem(174)<=x"000e000f" ;
instr_mem(175)<=x"040e0001" ;
instr_mem(176)<=x"06010005" ;
instr_mem(177)<=x"060e0011" ;
instr_mem(178)<=x"000e000f" ;
instr_mem(179)<=x"040e0001" ;
instr_mem(180)<=x"060e0011" ;
instr_mem(181)<=x"000e000f" ;
instr_mem(182)<=x"0501000e" ;
instr_mem(183)<=x"060e0010" ;
instr_mem(184)<=x"000e000f" ;
instr_mem(185)<=x"0502000e" ;
instr_mem(186)<=x"08020001";
instr_mem(187)<=x"060e0010" ;
instr_mem(188)<=x"000e000f" ;
instr_mem(189)<=x"040e0002" ;
instr_mem(190)<=x"060e0010" ;
instr_mem(191)<=x"000e000f" ;
instr_mem(192)<=x"050a000e" ;
instr_mem(193)<=x"0ce2000a" ;
instr_mem(194)<=x"060e0007" ;
instr_mem(195)<=x"000e000f" ;
instr_mem(196)<=x"0501000e" ;
instr_mem(197)<=x"060e0010" ;
instr_mem(198)<=x"000e000f" ;
instr_mem(199)<=x"040e0001" ;
instr_mem(200)<=x"060e0008" ;
instr_mem(201)<=x"000e000f" ;
instr_mem(202)<=x"0501000e" ;
instr_mem(203)<=x"060e0011" ;
instr_mem(204)<=x"000e000f" ;
instr_mem(205)<=x"040e0001" ;
instr_mem(206)<=x"060e0011" ;
instr_mem(207)<=x"000e000f" ;
instr_mem(208)<=x"0501000e" ;
instr_mem(209)<=x"060e0010" ;
instr_mem(210)<=x"000e000f" ;
instr_mem(211)<=x"0502000e" ;
instr_mem(212)<=x"00010002" ;
instr_mem(213)<=x"040e0001" ;
instr_mem(214)<=x"060e0010" ;
instr_mem(215)<=x"000e000f" ;
instr_mem(216)<=x"0501000e" ;
instr_mem(217)<=x"060e0007" ;
instr_mem(218)<=x"000e000f" ;
instr_mem(219)<=x"040e0001" ;
instr_mem(220)<=x"060e0008" ;
instr_mem(221)<=x"000e000f" ;
instr_mem(222)<=x"0501000e" ;
instr_mem(223)<=x"06020001" ;
instr_mem(224)<=x"00010002" ;
instr_mem(225)<=x"040e0001" ;
instr_mem(227)<=x"060e0009" ;
instr_mem(228)<=x"000e000f" ;
instr_mem(229)<=x"0501000e" ;
instr_mem(230)<=x"060e0010" ;
instr_mem(231)<=x"000e000f" ;
instr_mem(232)<=x"040e0001" ;
instr_mem(233)<=x"06010005" ;
instr_mem(234)<=x"060e0011" ;
instr_mem(235)<=x"000e000f" ;
instr_mem(236)<=x"040e0001" ;
instr_mem(237)<=x"060e0011" ;
instr_mem(238)<=x"000e000f" ;
instr_mem(239)<=x"0501000e" ;
instr_mem(240)<=x"060e0010" ;
instr_mem(241)<=x"000e000f" ;
instr_mem(242)<=x"0502000e" ;
instr_mem(243)<=x"08020001";
instr_mem(244)<=x"060e0010" ;
instr_mem(245)<=x"000e000f" ;
instr_mem(246)<=x"040e0002" ;
instr_mem(247)<=x"060e0010" ;
instr_mem(248)<=x"000e000f" ;
instr_mem(249)<=x"050a000e" ;
instr_mem(250)<=x"0c107000a" ;
instr_mem(251)<=x"060e000a" ;
instr_mem(252)<=x"000e000f" ;
instr_mem(253)<=x"0501000e" ;
instr_mem(254)<=x"06020001" ;
instr_mem(255)<=x"00010002" ;
instr_mem(256)<=x"040e0001" ;
instr_mem(257)<=x"060e0009" ;
instr_mem(258)<=x"000e000f" ;
instr_mem(259)<=x"0501000e" ;
instr_mem(260)<=x"06020001" ;
instr_mem(261)<=x"00010002" ;
instr_mem(262)<=x"040e0001" ;
instr_mem(264)<=x"060e0006" ;
instr_mem(265)<=x"000e000f" ;
instr_mem(266)<=x"0501000e" ;
instr_mem(267)<=x"060e0010" ;
instr_mem(268)<=x"000e000f" ;
instr_mem(269)<=x"040e0001" ;
instr_mem(270)<=x"06010005" ;
instr_mem(271)<=x"060e0011" ;
instr_mem(272)<=x"000e000f" ;
instr_mem(273)<=x"040e0001" ;
instr_mem(274)<=x"060e0011" ;
instr_mem(275)<=x"000e000f" ;
instr_mem(276)<=x"0501000e" ;
instr_mem(277)<=x"060e0010" ;
instr_mem(278)<=x"000e000f" ;
instr_mem(279)<=x"0502000e" ;
instr_mem(280)<=x"08020001";
instr_mem(281)<=x"060e0010" ;
instr_mem(282)<=x"000e000f" ;
instr_mem(283)<=x"040e0002" ;
instr_mem(284)<=x"060e0010" ;
instr_mem(285)<=x"000e000f" ;
instr_mem(286)<=x"050a000e" ;
instr_mem(287)<=x"0c169000a" ;
instr_mem(288)<=x"06010000" ;
instr_mem(289)<=x"060e0010" ;
instr_mem(290)<=x"000e000f" ;
instr_mem(291)<=x"040e0001" ;
instr_mem(292)<=x"060e0010" ;
instr_mem(293)<=x"000e000f" ;
instr_mem(294)<=x"0501000e" ;
instr_mem(295)<=x"060e0008" ;
instr_mem(296)<=x"000e000f" ;
instr_mem(297)<=x"040e0001" ;
instr_mem(298)<=x"060e0008" ;
instr_mem(299)<=x"000e000f" ;
instr_mem(300)<=x"0501000e" ;
instr_mem(301)<=x"060e0010" ;
instr_mem(302)<=x"000e000f" ;
instr_mem(303)<=x"040e0001" ;
instr_mem(304)<=x"06010005" ;
instr_mem(305)<=x"060e0011" ;
instr_mem(306)<=x"000e000f" ;
instr_mem(307)<=x"040e0001" ;
instr_mem(308)<=x"060e0011" ;
instr_mem(309)<=x"000e000f" ;
instr_mem(310)<=x"0501000e" ;
instr_mem(311)<=x"060e0010" ;
instr_mem(312)<=x"000e000f" ;
instr_mem(313)<=x"0502000e" ;
instr_mem(314)<=x"08020001";
instr_mem(315)<=x"060e0010" ;
instr_mem(316)<=x"000e000f" ;
instr_mem(317)<=x"040e0002" ;
instr_mem(318)<=x"060e0010" ;
instr_mem(319)<=x"000e000f" ;
instr_mem(320)<=x"050a000e" ;
instr_mem(321)<=x"0c162000a" ;
instr_mem(322)<=x"060e000b" ;
instr_mem(323)<=x"000e000f" ;
instr_mem(324)<=x"0501000e" ;
instr_mem(325)<=x"060e0010" ;
instr_mem(326)<=x"000e000f" ;
instr_mem(327)<=x"040e0001" ;
instr_mem(328)<=x"060e0008" ;
instr_mem(329)<=x"000e000f" ;
instr_mem(330)<=x"0501000e" ;
instr_mem(331)<=x"060e0011" ;
instr_mem(332)<=x"000e000f" ;
instr_mem(333)<=x"040e0001" ;
instr_mem(334)<=x"060e0011" ;
instr_mem(335)<=x"000e000f" ;
instr_mem(336)<=x"0501000e" ;
instr_mem(337)<=x"060e0010" ;
instr_mem(338)<=x"000e000f" ;
instr_mem(339)<=x"0502000e" ;
instr_mem(340)<=x"00010002" ;
instr_mem(341)<=x"040e0001" ;
instr_mem(342)<=x"060e0010" ;
instr_mem(343)<=x"000e000f" ;
instr_mem(344)<=x"0501000e" ;
instr_mem(345)<=x"060e000b" ;
instr_mem(346)<=x"000e000f" ;
instr_mem(347)<=x"040e0001" ;
instr_mem(348)<=x"060e0008" ;
instr_mem(349)<=x"000e000f" ;
instr_mem(350)<=x"0501000e" ;
instr_mem(351)<=x"06020001" ;
instr_mem(352)<=x"00010002" ;
instr_mem(353)<=x"040e0001" ;
instr_mem(355)<=x"060e0006" ;
instr_mem(356)<=x"000e000f" ;
instr_mem(357)<=x"0501000e" ;
instr_mem(358)<=x"06020001" ;
instr_mem(359)<=x"00010002" ;
instr_mem(360)<=x"040e0001" ;
instr_mem(362)<=x"060f000f" ;
instr_mem(363)<=x"06020007" ;
instr_mem(364)<=x"05010002" ;
instr_mem(365)<=x"060e0010" ;
instr_mem(366)<=x"040e0001" ;
instr_mem(367)<=x"06020005" ;
instr_mem(368)<=x"05010002" ;
instr_mem(369)<=x"060e0011" ;
instr_mem(370)<=x"040e0001" ;
instr_mem(371)<=x"0d000173" ;
instr_mem(372)<=x"060f0000" ;
instr_mem(373)<=x"060e0010" ;
instr_mem(374)<=x"000e000f" ;
instr_mem(375)<=x"0501000e" ;
instr_mem(376)<=x"060e000d" ;
instr_mem(377)<=x"000e000f" ;
instr_mem(378)<=x"040e0001" ;
instr_mem(379)<=x"060f000f" ;
instr_mem(380)<=x"06020006" ;
instr_mem(381)<=x"05010002" ;
instr_mem(382)<=x"060e0010" ;
instr_mem(383)<=x"040e0001" ;
instr_mem(384)<=x"06020008" ;
instr_mem(385)<=x"05010002" ;
instr_mem(386)<=x"060e0011" ;
instr_mem(387)<=x"040e0001" ;
instr_mem(388)<=x"0d000184" ;
instr_mem(389)<=x"060f0000" ;
instr_mem(390)<=x"060e0010" ;
instr_mem(391)<=x"000e000f" ;
instr_mem(392)<=x"0501000e" ;
instr_mem(393)<=x"060e000e" ;
instr_mem(394)<=x"000e000f" ;
instr_mem(395)<=x"040e0001" ;
instr_mem(396)<=x"060f000f" ;
instr_mem(397)<=x"0602000d" ;
instr_mem(398)<=x"05010002" ;
instr_mem(399)<=x"060e0010" ;
instr_mem(400)<=x"040e0001" ;
instr_mem(401)<=x"0602000e" ;
instr_mem(402)<=x"05010002" ;
instr_mem(403)<=x"060e0011" ;
instr_mem(404)<=x"040e0001" ;
instr_mem(405)<=x"0d000195" ;
instr_mem(406)<=x"060f0000" ;
instr_mem(407)<=x"060e0010" ;
instr_mem(408)<=x"000e000f" ;
instr_mem(409)<=x"0501000e" ;
instr_mem(410)<=x"060e000f" ;
instr_mem(411)<=x"000e000f" ;
instr_mem(412)<=x"040e0001" ;
instr_mem(413)<=x"060e0007" ;
instr_mem(414)<=x"000e000f" ;
instr_mem(415)<=x"0501000e" ;
instr_mem(416)<=x"060e0010" ;
instr_mem(417)<=x"000e000f" ;
instr_mem(418)<=x"040e0001" ;
instr_mem(419)<=x"06010005" ;
instr_mem(420)<=x"060e0011" ;
instr_mem(421)<=x"000e000f" ;
instr_mem(422)<=x"040e0001" ;
instr_mem(423)<=x"060e0011" ;
instr_mem(424)<=x"000e000f" ;
instr_mem(425)<=x"0501000e" ;
instr_mem(426)<=x"060e0010" ;
instr_mem(427)<=x"000e000f" ;
instr_mem(428)<=x"0502000e" ;
instr_mem(429)<=x"07020001" ;
instr_mem(430)<=x"060e0010" ;
instr_mem(431)<=x"000e000f" ;
instr_mem(432)<=x"040e0002" ;
instr_mem(433)<=x"060e0010" ;
instr_mem(434)<=x"000e000f" ;
instr_mem(435)<=x"050a000e" ;
instr_mem(436)<=x"0c1bf000a" ;
instr_mem(437)<=x"06010005" ;
instr_mem(438)<=x"060e0010" ;
instr_mem(439)<=x"000e000f" ;
instr_mem(440)<=x"040e0001" ;
instr_mem(441)<=x"060e0010" ;
instr_mem(442)<=x"000e000f" ;
instr_mem(443)<=x"0501000e" ;
instr_mem(444)<=x"060e000c" ;
instr_mem(445)<=x"000e000f" ;
instr_mem(446)<=x"040e0001" ;
instr_mem(448)<=x"06010003" ;
instr_mem(449)<=x"060e0010" ;
instr_mem(450)<=x"000e000f" ;
instr_mem(451)<=x"040e0001" ;
instr_mem(452)<=x"060e0010" ;
instr_mem(453)<=x"000e000f" ;
instr_mem(454)<=x"0501000e" ;
instr_mem(455)<=x"060e000c" ;
instr_mem(456)<=x"000e000f" ;
instr_mem(457)<=x"040e0001" ;

	






process


 begin
 --wait for 50ns;
  wait until rising_edge(Clk); 
  Bus_data <= "ZZZZZZZZZZZZZZZZ";
 -- Bus_control<= "ZZ";
  --change everything to double the size of operation 
  if(reg_curr_instr(31 downto 24)= x"00") then-- ADD
			 if(status=0)then -- we have to put it to status =1 for reasigning the value 
					regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
					regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
					status<=status+1;
					curr_op<=x"00"; 
				elsif(status=1) then
					reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
					status<=0;
					currentInst<= currentInst+1;
				--	assert false report "Simulation Finished" severity failure;  -- debug stop 
			 
			 end if;
	 
  elsif(reg_curr_instr(31 downto 24)= x"01") then-- sub
		  if(status=0)then -- we have to put it to status =1 for reasigning the value 
					regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
					regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
					--curr_op<=x"ff";  -- the current operation changes only after the process so it remains to FF when we need it to work
					status<=status+1;
					curr_op<=x"01"; 
				elsif(status=1) then
					reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
					status<=0;
					currentInst<= currentInst+1;
				--	assert false report "Simulation Finished" severity failure;  -- debug stop 
			 
			 end if;
	 
	 
  elsif(reg_curr_instr(31 downto 24)= x"02") then-- MUL
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
					regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
					regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
					--curr_op<=x"ff";  -- the current operation changes only after the process so it remains to FF when we need it to work
					status<=status+1;
					curr_op<=x"02"; 
				elsif(status=1) then
					reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
					status<=0;
					currentInst<= currentInst+1;
				--	assert false report "Simulation Finished" severity failure;  -- debug stop 
			 
			 end if;
	 
	 
  elsif(reg_curr_instr(31 downto 24)= x"03") then-- DIV
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
					regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
					regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
					--curr_op<=x"ff";  -- the current operation changes only after the process so it remains to FF when we need it to work
					status<=status+1;
					curr_op<=x"03"; 
				elsif(status=1) then
					reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
					status<=0;
					currentInst<= currentInst+1;
				--	assert false report "Simulation Finished" severity failure;  -- debug stop 
			 
			 end if;
	 
  elsif(reg_curr_instr(31 downto 24)= x"04") then-- STORE at mem[Rx] = Ry
			if(status=0)then
				curr_op<="ZZZZZZZZ";
				Bus_address <= reg_curr_instr(23 downto 16);
				Bus_data <= reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- might need to put it 7 downto 0
				Bus_control<="01";
				status<=status+1; -- <=0 
				elsif(status=1) then
					status<=0;
					Bus_control<="ZZ";
				currentInst<= currentInst+1;
			 end if;	 
	 
	elsif(reg_curr_instr(31 downto 24)= x"05") then-- LOAD in Rx the value from @adr y
			if(status=0)then
				curr_op<="ZZZZZZZZ";
				Bus_address <= reg_curr_instr(7 downto 0);
				Bus_control<="00";
				status<=status+1;
			elsif(status=1)then
				 status<=status+1;
			elsif(status=2)then
				 reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=Bus_data;
				 status<=0;
				Bus_control<="ZZ"; -- add a default value
				 Bus_data<="ZZZZZZZZZZZZZZZZ";
				 currentInst<= currentInst+1;
				 
			--	assert false report "Simulation Finished" severity failure;  -- debug stop 
			 end if;	 
	 
	elsif(reg_curr_instr(31 downto 24)= x"06") then-- afc int Rx the value of y
			if(status=0)then
			--	curr_op<="ZZZZZZZZ";
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=reg_curr_instr(15 downto 0);
				status<=0;
				currentInst<= currentInst+1;
			end if;	
		
	 
	 
	elsif(reg_curr_instr(31 downto 24)= x"07") then-- Equality
	--assert false report "Simulation Finished" severity failure;  -- debug stop 
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
				regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
				regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
				status<=status+1;
				curr_op<=x"07"; 
			elsif(status=1) then
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
				status<=0;
				currentInst<= currentInst+1;
			--	assert false report "Simulation Finished" severity failure;  -- debug stop 
		 
			end if;
	 
	 
	 elsif(reg_curr_instr(31 downto 24)= x"08") then-- inf
	 --assert false report "Simulation Finished" severity failure;  -- debug stop 
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
				regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
				regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
				status<=status+1;
				curr_op<=x"08"; 
			elsif(status=1) then
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
				status<=0;
				currentInst<= currentInst+1;
			--	assert false report "Simulation Finished" severity failure;  -- debug stop 
		 
			end if;
	 
	 elsif(reg_curr_instr(31 downto 24)= x"09") then-- Inf superior
	 --assert false report "Simulation Finished" severity failure;  -- debug stop 
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
				regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
				regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
				status<=status+1;
				curr_op<=x"09"; 
			elsif(status=1) then
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
				status<=0;
				currentInst<= currentInst+1;
			--	assert false report "Simulation Finished" severity failure;  -- debug stop 
		 
			end if;
		 
	 elsif(reg_curr_instr(31 downto 24)= x"0a") then-- superior
	 --assert false report "Simulation Finished" severity failure;  -- debug stop 
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
				regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
				regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
				status<=status+1;
				curr_op<=x"0a"; 
			elsif(status=1) then
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
				status<=0;
				currentInst<= currentInst+1;
			--	assert false report "Simulation Finished" severity failure;  -- debug stop 
		 
			end if;
		 
	 
	 elsif(reg_curr_instr(31 downto 24)= x"0b") then-- superior equal
	 --assert false report "Simulation Finished" severity failure;  -- debug stop 
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
				regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
				regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
				status<=status+1;
				curr_op<=x"0b"; 
			elsif(status=1) then
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
				status<=0;
				currentInst<= currentInst+1;
			--	assert false report "Simulation Finished" severity failure;  -- debug stop 
		 
			end if;
			
	elsif(reg_curr_instr(31 downto 24)= x"0c") then-- JMP
	--assert false report "Simulation Finished" severity failure;  -- debug stop 
			if(status=0)then
			currentInst<=to_integer(unsigned(reg_curr_instr(23 downto 16)))+1; -- we increment it automaticly
			--	status<=0;
			end if ;
	elsif(reg_curr_instr(31 downto 24)= x"0d") then-- JMPC at @x if y ==0
	--assert false report "Simulation Finished" severity failure;  -- debug stop 
			if(status=0)then
				if(reg(to_integer(unsigned(reg_curr_instr(15 downto 0))))=x"0000") then
					currentInst<=to_integer(unsigned(reg_curr_instr(23 downto 16)))+1; -- we increment it automaticly
				else
					currentInst<= currentInst+1;
				end if;
			end if ;
	 
	
-- ADD constant to size of each register
	
	elsif(reg_curr_instr(31 downto 24)= x"0e") then-- CALL
	--assert false report "Simulation Finished" severity failure;  -- debug stop 
			if(status=0)then
				--do we need to add +1 all the time
					reg_recursivity(currentRecursivityLevel)<=std_logic_vector(to_unsigned(currentInst,16)); -- +1 ?!?!
					currentRecursivityLevel<=currentRecursivityLevel+1;
					currentInst<=to_integer(unsigned( reg_curr_instr(23 downto 16))) +1;
				
			end if ;
	 
	 	 
	elsif(reg_curr_instr(31 downto 24)= x"0F") then-- RET
	--assert false report "Simulation Finished" severity failure;  -- debug stop 
			if(status=0)then
				
				-- DOES THIS WORK ?
				
					currentRecursivityLevel<=currentRecursivityLevel-1;
					currentInst<=to_integer(unsigned(reg_recursivity(currentRecursivityLevel-1)));
				
			end if ;	 
	 
	 
	 
	 
  end if;
  
 
 end process;
 curr_op<="ZZZZZZZZ";
 reg_curr_instr <= instr_mem(currentInst);
 --Bus_data <= data;

end Behavioral;

