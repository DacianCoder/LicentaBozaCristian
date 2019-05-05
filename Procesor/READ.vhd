----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:20:27 05/05/2019 
-- Design Name: 
-- Module Name:    READ - Behavioral 
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
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

package bus_multiplexer_pkg is
        type bus_array is array(natural range <>) of std_logic_vector;
end package;


library IEEE;
use IEEE.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_textio.all;
use std.textio.all;
use work.bus_multiplexer_pkg.all;

entity READ is
    port( dataout : out bus_array(2048 downto 0)(31 downto 0));
end entity;
    architecture bev of READ is
        type mem is array (2048 downto 0) of std_logic_vector(31 downto 0);
        signal t_mem : mem;
        begin
            process(address)
                FILE f : TEXT;
                constant filename : string :="instructions.txt";
                VARIABLE L : LINE;
                variable i : integer:=0;
                variable b : std_logic_vector(31 downto 0);
                begin
                    
                    File_Open (f,FILENAME, read_mode);	
			while ((i<=2048) and (not EndFile (f))) loop
			readline (f, l);
			next when l(1) = '#'; 
			hread(l, b);
			t_mem(i) <= b;
			i := i + 1;
		end loop;
		File_Close (f);                    
                dataout<=t_mem;
            end process;
        end bev;

architecture Behavioral of READ is

begin


end Behavioral;

