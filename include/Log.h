
// #include "Core.h"
#include "spdlog/spdlog.h"

namespace Brix
{
    class Log {
        public: 
            static void init(); 
            inline static std::shared_ptr<spdlog::logger>& get_core_logger() {return s_core_logger; }
            inline static std::shared_ptr<spdlog::logger>& get_client_logger() {return s_client_logger; }

        private: 
            static std::shared_ptr<spdlog::logger> s_core_logger; 
            static std::shared_ptr<spdlog::logger> s_client_logger; 

    };
} // namespace Brix


#define BX_CORE_WARN(...) ::Brix::Log::get_core_logger()->warn(__VA_ARGS__)
#define BX_CORE_INFO(...) ::Brix::Log::get_core_logger()->info(__VA_ARGS__)
#define BX_CORE_TRACE(...) ::Brix::Log::get_core_logger()->trace(__VA_ARGS__)
#define BX_CORE_ERROR(...) ::Brix::Log::get_core_logger()->error(__VA_ARGS__)

#define BX_WARN(...) ::Brix::Log::get_client_logger()->warn(__VA_ARGS__)
#define BX_INFO(...) ::Brix::Log::get_client_logger()->info(__VA_ARGS__)
#define BX_TRACE(...) ::Brix::Log::get_client_logger()->trace(__VA_ARGS__)
#define BX_ERROR(...) ::Brix::Log::get_client_logger()->error(__VA_ARGS__)
