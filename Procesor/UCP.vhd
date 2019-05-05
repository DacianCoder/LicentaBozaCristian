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
use work.pckg.all;
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


type register_array is array(0 to 2048) of STD_LOGIC_VECTOR (31 downto 0); -- check for a way to put  variables 
signal instr_mem: array32;

component read_text is
    port(clk : in std_logic;
			dataout : out array32);
end component;

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

--signal readClk : std_logic:='0';


component UAL	
    Port(  A : in  STD_LOGIC_VECTOR (15 downto 0);
           B : in  STD_LOGIC_VECTOR (15 downto 0);
           Op : in  STD_LOGIC_VECTOR (7 downto 0);
           S : out  STD_LOGIC_VECTOR (15 downto 0);
           Flag : out  STD_LOGIC_VECTOR (3 downto 0) ); -- enable output of the data 
end component;

begin


ALU:UAL port map(regSelectorA,regSelectorB,curr_op,result,flag); -- we always put the resultat S in r1
--READT:read_text port map(readClk,instr_mem);
            --  op @1 @2/
--####### How to use the instructions ######
--	Format: [Op][Op]AABBBB (first 2 operations; next 2 A, last 4 B.
--	Ops: |00 |01 |02 |03 |   04  05   06  07 08   09  0A   0B  0C  0D    0E  0F
--		  |ADD|SUB|MUL|DIV|STORE LOAD AFC EQU INF InfE Sup SupE Jmp Jmpc Call Ret
instr_mem(0)<=x"06010004";
instr_mem(1)<=x"060e0000";
instr_mem(2)<=x"000e000f";
instr_mem(3)<=x"040e0001";
instr_mem(4)<=x"0c2d0000";
instr_mem(5)<=x"060e0001";
instr_mem(6)<=x"000e000f";
instr_mem(7)<=x"0501000e";
instr_mem(8)<=x"060e0003";
instr_mem(9)<=x"000e000f";
instr_mem(10)<=x"040e0001";
instr_mem(11)<=x"060e0002";
instr_mem(12)<=x"000e000f";
instr_mem(13)<=x"0501000e";
instr_mem(14)<=x"060e0004";
instr_mem(15)<=x"000e000f";
instr_mem(16)<=x"040e0001";
instr_mem(17)<=x"060e0004";
instr_mem(18)<=x"000e000f";
instr_mem(19)<=x"0501000e";
instr_mem(20)<=x"060e0003";
instr_mem(21)<=x"000e000f";
instr_mem(22)<=x"0502000e";
instr_mem(23)<=x"0b020001";
instr_mem(24)<=x"060e0003";
instr_mem(25)<=x"000e000f";
instr_mem(26)<=x"040e0002";
instr_mem(27)<=x"060e0003";
instr_mem(28)<=x"000e000f";
instr_mem(29)<=x"050a000e";
instr_mem(30)<=x"0d26000a";
instr_mem(31)<=x"060e0001";
instr_mem(32)<=x"000e000f";
instr_mem(33)<=x"0501000e";
instr_mem(34)<=x"060e0001";
instr_mem(35)<=x"000e000f";
instr_mem(36)<=x"040e0001";
instr_mem(37)<=x"0f010001";
instr_mem(38)<=x"0c2d000a";
instr_mem(39)<=x"060e0002";
instr_mem(40)<=x"000e000f";
instr_mem(41)<=x"0501000e";
instr_mem(42)<=x"060e0001";
instr_mem(43)<=x"000e000f";
instr_mem(44)<=x"040e0001";
instr_mem(45)<=x"0f010001";
instr_mem(46)<=x"0601000a";
instr_mem(47)<=x"060e0003";
instr_mem(48)<=x"000e000f";
instr_mem(49)<=x"040e0001";
instr_mem(50)<=x"06010005";
instr_mem(51)<=x"060e0005";
instr_mem(52)<=x"000e000f";
instr_mem(53)<=x"040e0001";
instr_mem(54)<=x"060e0004";
instr_mem(55)<=x"000e000f";
instr_mem(56)<=x"0501000e";
instr_mem(57)<=x"060e0009";
instr_mem(58)<=x"000e000f";
instr_mem(59)<=x"040e0001";
instr_mem(60)<=x"06010001";
instr_mem(61)<=x"060e000a";
instr_mem(62)<=x"000e000f";
instr_mem(63)<=x"040e0001";
instr_mem(64)<=x"060e000a";
instr_mem(65)<=x"000e000f";
instr_mem(66)<=x"0501000e";
instr_mem(67)<=x"060e0009";
instr_mem(68)<=x"000e000f";
instr_mem(69)<=x"0502000e";
instr_mem(70)<=x"07020001";
instr_mem(71)<=x"060e0009";
instr_mem(72)<=x"000e000f";
instr_mem(73)<=x"040e0002";
instr_mem(74)<=x"060e0009";
instr_mem(75)<=x"000e000f";
instr_mem(76)<=x"050a000e";
instr_mem(77)<=x"0d58000a";
instr_mem(78)<=x"0601000a";
instr_mem(79)<=x"060e0009";
instr_mem(80)<=x"000e000f";
instr_mem(81)<=x"040e0001";
instr_mem(82)<=x"060e0009";
instr_mem(83)<=x"000e000f";
instr_mem(84)<=x"0501000e";
instr_mem(85)<=x"060e0006";
instr_mem(86)<=x"000e000f";
instr_mem(87)<=x"040e0001";
instr_mem(88)<=x"0c62000a";
instr_mem(89)<=x"06010002";
instr_mem(90)<=x"060e0009";
instr_mem(91)<=x"000e000f";
instr_mem(92)<=x"040e0001";
instr_mem(93)<=x"060e0009";
instr_mem(94)<=x"000e000f";
instr_mem(95)<=x"0501000e";
instr_mem(96)<=x"060e0006";
instr_mem(97)<=x"000e000f";
instr_mem(98)<=x"040e0001";
instr_mem(99)<=x"060e0005";
instr_mem(100)<=x"000e000f";
instr_mem(101)<=x"0501000e";
instr_mem(102)<=x"060e0009";
instr_mem(103)<=x"000e000f";
instr_mem(104)<=x"040e0001";
instr_mem(105)<=x"060e0006";
instr_mem(106)<=x"000e000f";
instr_mem(107)<=x"0501000e";
instr_mem(108)<=x"060e000a";
instr_mem(109)<=x"000e000f";
instr_mem(110)<=x"040e0001";
instr_mem(111)<=x"060e000a";
instr_mem(112)<=x"000e000f";
instr_mem(113)<=x"0501000e";
instr_mem(114)<=x"060e0009";
instr_mem(115)<=x"000e000f";
instr_mem(116)<=x"0502000e";
instr_mem(117)<=x"00010002";
instr_mem(118)<=x"040e0001";
instr_mem(119)<=x"06010001";
instr_mem(120)<=x"060e000a";
instr_mem(121)<=x"000e000f";
instr_mem(122)<=x"040e0001";
instr_mem(123)<=x"060e000a";
instr_mem(124)<=x"000e000f";
instr_mem(125)<=x"0501000e";
instr_mem(126)<=x"060e0009";
instr_mem(127)<=x"000e000f";
instr_mem(128)<=x"0502000e";
instr_mem(129)<=x"00010002";
instr_mem(130)<=x"040e0001";
instr_mem(131)<=x"060e0009";
instr_mem(132)<=x"000e000f";
instr_mem(133)<=x"0501000e";
instr_mem(134)<=x"060e0005";
instr_mem(135)<=x"000e000f";
instr_mem(136)<=x"040e0001";
instr_mem(137)<=x"060e0007";
instr_mem(138)<=x"000e000f";
instr_mem(139)<=x"0501000e";
instr_mem(140)<=x"060e0009";
instr_mem(141)<=x"000e000f";
instr_mem(142)<=x"040e0001";
instr_mem(143)<=x"060e0003";
instr_mem(144)<=x"000e000f";
instr_mem(145)<=x"0501000e";
instr_mem(146)<=x"060e000a";
instr_mem(147)<=x"000e000f";
instr_mem(148)<=x"040e0001";
instr_mem(149)<=x"060e000a";
instr_mem(150)<=x"000e000f";
instr_mem(151)<=x"0501000e";
instr_mem(152)<=x"060e0009";
instr_mem(153)<=x"000e000f";
instr_mem(154)<=x"0502000e";
instr_mem(155)<=x"08020001";
instr_mem(156)<=x"060e0009";
instr_mem(157)<=x"000e000f";
instr_mem(158)<=x"040e0002";
instr_mem(159)<=x"060e0009";
instr_mem(160)<=x"000e000f";
instr_mem(161)<=x"050a000e";
instr_mem(162)<=x"0dc1000a";
instr_mem(163)<=x"060e0004";
instr_mem(164)<=x"000e000f";
instr_mem(165)<=x"0501000e";
instr_mem(166)<=x"060e0009";
instr_mem(167)<=x"000e000f";
instr_mem(168)<=x"040e0001";
instr_mem(169)<=x"06010002";
instr_mem(170)<=x"060e000a";
instr_mem(171)<=x"000e000f";
instr_mem(172)<=x"040e0001";
instr_mem(173)<=x"060e000a";
instr_mem(174)<=x"000e000f";
instr_mem(175)<=x"0501000e";
instr_mem(176)<=x"060e0009";
instr_mem(177)<=x"000e000f";
instr_mem(178)<=x"0502000e";
instr_mem(179)<=x"00010002";
instr_mem(180)<=x"040e0001";
instr_mem(181)<=x"060e0009";
instr_mem(182)<=x"000e000f";
instr_mem(183)<=x"0501000e";
instr_mem(184)<=x"060e0004";
instr_mem(185)<=x"000e000f";
instr_mem(186)<=x"040e0001";
instr_mem(187)<=x"060e0007";
instr_mem(188)<=x"000e000f";
instr_mem(189)<=x"0501000e";
instr_mem(190)<=x"06020001";
instr_mem(191)<=x"00010002";
instr_mem(192)<=x"040e0001";
instr_mem(193)<=x"0c880001";
instr_mem(194)<=x"060f0008";
instr_mem(195)<=x"06020005";
instr_mem(196)<=x"05010002";
instr_mem(197)<=x"060e0009";
instr_mem(198)<=x"040e0001";
instr_mem(199)<=x"06020004";
instr_mem(200)<=x"05010002";
instr_mem(201)<=x"060e000a";
instr_mem(202)<=x"040e0001";
instr_mem(203)<=x"0e0800cb";
instr_mem(204)<=x"060f0000";
instr_mem(205)<=x"060e0009";
instr_mem(206)<=x"000e000f";
instr_mem(207)<=x"0501000e";
instr_mem(208)<=x"060e0008";
instr_mem(209)<=x"000e000f";
instr_mem(210)<=x"040e0001";

process


 begin

  wait until rising_edge(Clk); 
  Bus_data <= "ZZZZZZZZZZZZZZZZ";
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
			 end if;
	 
	elsif(reg_curr_instr(31 downto 24)= x"04") then-- STORE at mem[reg[Rx]] = reg[Ry]
			if(status=0)then
				curr_op<="ZZZZZZZZ";
				Bus_address<=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))(7 downto 0);
				Bus_data<=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- might need to put it 7 downto 0
				Bus_control<="01";
				status<=status+1; -- <=0 
			elsif(status=1) then
				status<=0;
				Bus_control<="ZZ";
				currentInst<= currentInst+1;
			 end if;	 
	 
	elsif(reg_curr_instr(31 downto 24)= x"05") then-- LOAD in Rx the value from reg[y]
			if(status=0)then
				curr_op<="ZZZZZZZZ";
				Bus_address<=reg(to_integer(unsigned(reg_curr_instr(7 downto 0))))(7 downto 0);
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
				 
			 end if;	 
	 
	elsif(reg_curr_instr(31 downto 24)= x"06") then-- afc int Rx the value of y
			if(status=0)then
			--	curr_op<="ZZZZZZZZ";
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=reg_curr_instr(15 downto 0);
				status<=0;
				currentInst<= currentInst+1;
			end if;	
		
	 
	 
	elsif(reg_curr_instr(31 downto 24)= x"07") then-- Equality
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
				regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
				regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
				status<=status+1;
				curr_op<=x"07"; 
			elsif(status=1) then
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
				status<=0;
				currentInst<= currentInst+1;
		 
			end if;
	 
	 
	 elsif(reg_curr_instr(31 downto 24)= x"08") then-- inf
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
				regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
				regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
				status<=status+1;
				curr_op<=x"08"; 
			elsif(status=1) then
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
				status<=0;
				currentInst<= currentInst+1;
		 
			end if;
	 
	 elsif(reg_curr_instr(31 downto 24)= x"09") then-- Inf equal
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
				regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
				regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
				status<=status+1;
				curr_op<=x"09"; 
			elsif(status=1) then
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
				status<=0;
				currentInst<= currentInst+1;
		 
			end if;
		 
	 elsif(reg_curr_instr(31 downto 24)= x"0a") then-- superior
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
				regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
				regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
				status<=status+1;
				curr_op<=x"0a"; 
			elsif(status=1) then
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
				status<=0;
				currentInst<= currentInst+1;
		 
			end if;
		 
	 
	 elsif(reg_curr_instr(31 downto 24)= x"0b") then-- superior equal
			if(status=0)then -- we have to put it to status =1 for reasigning the value 
				regSelectorA <=reg(to_integer(unsigned(reg_curr_instr(23 downto 16))));
				regSelectorB <=reg(to_integer(unsigned(reg_curr_instr(15 downto 0)))); -- maybe 7 downto 0
				status<=status+1;
				curr_op<=x"0b"; 
			elsif(status=1) then
				reg(to_integer(unsigned(reg_curr_instr(23 downto 16))))<=result;
				status<=0;
				currentInst<= currentInst+1;
			end if;
			
	elsif(reg_curr_instr(31 downto 24)= x"0c") then-- JMP
			if(status=0)then
				currentInst<=to_integer(unsigned(reg_curr_instr(23 downto 16)))+1; -- we increment it automaticly
			end if ;
	elsif(reg_curr_instr(31 downto 24)= x"0d") then-- JMPC at @x if y ==0
			if(status=0)then
				if(reg(to_integer(unsigned(reg_curr_instr(15 downto 0))))=x"0000") then
					currentInst<=to_integer(unsigned(reg_curr_instr(23 downto 16)))+1; -- we increment it automaticly
				else
					currentInst<= currentInst+1;
				end if;
			end if ;
	
	elsif(reg_curr_instr(31 downto 24)= x"0e") then-- CALL
			reg_recursivity(currentRecursivityLevel)<=std_logic_vector(to_unsigned(currentInst,16)); -- +1 ?!?!
			currentRecursivityLevel<=currentRecursivityLevel+1;
			currentInst<=to_integer(unsigned( reg_curr_instr(23 downto 16))) +1;
				
	 	 
	elsif(reg_curr_instr(31 downto 24)= x"0F") then-- RET
			currentRecursivityLevel<=currentRecursivityLevel-1;
			currentInst<=to_integer(unsigned(reg_recursivity(currentRecursivityLevel-1)))+1; 
	
	end if;
  
 
 end process;
 curr_op<="ZZZZZZZZ";
 reg_curr_instr <= instr_mem(currentInst);

end Behavioral;

