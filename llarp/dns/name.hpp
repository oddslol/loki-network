#ifndef LLARP_DNS_NAME_HPP
#define LLARP_DNS_NAME_HPP

#include <buffer.h>
#include <net_int.hpp>

#include <string>

namespace llarp
{
  namespace dns
  {
    using Name_t = std::string;

    /// decode name from buffer
    bool
    DecodeName(llarp_buffer_t* buf, Name_t& name);

    /// encode name to buffer
    bool
    EncodeName(llarp_buffer_t* buf, const Name_t& name);

    bool
    DecodePTR(const Name_t& name, huint32_t& ip);

  }  // namespace dns
}  // namespace llarp

#endif
