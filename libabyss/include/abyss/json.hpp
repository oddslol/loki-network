#ifndef __ABYSS_JSON_JSON_HPP
#define __ABYSS_JSON_JSON_HPP

#include <memory>
//#if __cplusplus >= 201703L
#if 0
#include <unordered_map>
#include <any>
namespace abyss
{
  namespace json
  {
    using Object = std::unordered_map< std::string, std::any >;
  }
}  // namespace abyss
#else
#include <rapidjson/document.h>
namespace abyss
{
  namespace json
  {
    using Document = rapidjson::Document;
    using Value    = rapidjson::Value;
  }  // namespace json
}  // namespace abyss
#endif
namespace abyss
{
#if __cplusplus >= 201703L
  using string_view = std::string_view;
#else
  using string_view = std::string;
#endif
  namespace json
  {
    struct IParser
    {
      virtual ~IParser(){};

      /// result from feeding data to parser
      enum Result
      {
        /// we need more data to finish parsing
        eNeedData,
        /// we have parsed the object fully
        eDone,
        /// we have a parsing syntax error
        eParseError
      };

      /// feed data to parser return true if successful
      virtual bool
      FeedData(const char *buf, size_t sz) = 0;
      /// parse internal buffer
      virtual Result
      Parse(Document &obj) const = 0;
    };

    /// create new parser
    IParser *
    MakeParser(size_t contentSize);

    void
    ToString(const json::Document &obj, std::string &out);

  }  // namespace json
}  // namespace abyss

#endif
