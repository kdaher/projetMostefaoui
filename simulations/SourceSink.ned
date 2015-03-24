//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package projet_mostefaoui.simulations;

import projet_mostefaoui.Source;
import projet_mostefaoui.Sink;
import projet_mostefaoui.CH;

//
// Sample network, consisting of a source and a sink.
//
network SourceSink
{
    submodules:
        source[3]: Source {
            @display("p=74,103");
        }
        sink[1]: Sink {
            @display("p=410,113");
        }
        ch[1]: CH {
            @display("p=260,113");
        }
    connections:
        source[0].out --> ch[0].in++;
        source[1].out --> ch[0].in++;
        source[2].out --> ch[0].in++;
        ch[0].out --> sink[0].in;
}
