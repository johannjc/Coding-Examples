/*
 * Copyright (c) 2011, Damian Rouson, Jim Xia, and Xiaofeng Xu.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the names of Damian Rouson, Jim Xia, and Xiaofeng Xu nor the
 *       names of any other contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL DAMIAN ROUSON, JIM XIA, and XIAOFENG XU BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _H_FMT_
#define _H_FMT_
#include "globals.h"
#include <iostream>
#include <iomanip>
// The fmt(...) helper class helps hide the mess that in <iomanip>
struct fmt {
  explicit fmt(real_t value, int width=12, int prec=8) :
    v_(1, value), w_(width), p_(prec)
  {}
  explicit fmt(crd_t value, int width=12, int prec=8) :
    v_(value), w_(width), p_(prec)
  {}

  const crd_t v_;
  const int w_, p_;
};
inline std::ostream& operator<<(std::ostream &os, const fmt &v) {
  // Store format flags for the stream.
  std::ios_base::fmtflags flags = os.flags();
  // Force our own weird format.
  for(crd_t::const_iterator it = v.v_.begin(); it != v.v_.end(); ++it) {
    os << " " <<std::setw(v.w_) <<std::setprecision(v.p_) <<std::fixed
    	 << *it;
  }
  // Restore original format flags.
  os.flags(flags);
  return os;
}
#endif //! _H_FMT_
