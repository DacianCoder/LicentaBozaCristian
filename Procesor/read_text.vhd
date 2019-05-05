library IEEE;
use IEEE.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_textio.all;
USE ieee.numeric_std.all;
use work.pckg.all;
USE STD.textio.all;

entity read_text is
    port(
	 clk : in std_logic;
	 dataout : out array32);
end entity;
architecture bev of read_text is
    shared variable  t_mem : array32;
  signal test : std_logic_vector(31 downto 0);
  begin
		process(clk)
			 FILE f : TEXT;
			 constant filename : string :="instructions.txt";
			 VARIABLE L : LINE;
			 variable i : integer:=0;
			 begin
				  
			file_Open (f,FILENAME, read_mode);	
			while ((i<=2047) and (not EndFile (f))) loop
				readline (f, l);
				hread(l, t_mem(i)); 
				i := i + 1;
			end loop;
			File_Close (f);                    
			dataout<=t_mem;
	  end process;
	end bev;
