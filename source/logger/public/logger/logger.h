#pragma once

#include <logger/output/ilogoutput.h>
#include <logger/logdefinitions.h>

#include <utils/containers/uniquerealizationcontainer.h>
#include <utils/formatstring.h>
#include <utils/noncopyable.h>
#include <utils/numerictypes.h>

#include <vector>

namespace puma
{
    class Logger: public NonCopyable
    {
    public:

        void info( const LogCategory& _category, const char* _format, ... )
        {
            va_list args;
            va_start( args, _format );
            addLog( getCategoryInfo(_category), LogType::Info, formatString( _format, args ) );
            va_end( args );
        }

        void warning( const LogCategory& _category, const char* _format, ... )
        {
            va_list args;
            va_start( args, _format );
            addLog( getCategoryInfo( _category ), LogType::Warning, formatString( _format, args ) );
            va_end( args );
        }

        void error( const LogCategory& _category, const char* _format, ... )
        {
            va_list args;
            va_start(args, _format);
            addLog( getCategoryInfo( _category ), LogType::Error, formatString( _format, args ) );
            va_end( args );
        }

        LogCategory registerCategory( const std::string& _categoryName )
        {
            m_categoryNames.push_back( _categoryName );
            return LogCategory( (u32)m_categoryNames.size() );
        }

        template<class OutputClass>
        void addOutput()
        {
            if ( !m_outputs.isRegistered<OutputClass>() )
            {
                m_outputs.registerClass<OutputClass>();
            }

            m_outputs.add<OutputClass>();
        }

        template<class OutputClass>
        bool removeOutput()
        {
            m_outputs.remove<OutputClass>();
        }

    private:
        void addLog( const CategoryInfo& _categoryInfo, LogType _type, const std::string& _report )
        {
            m_outputs.traverse( [&]( const ILogOutput* output ) 
            {
                output->print( _categoryInfo, _type, _report.c_str() );
            } );
        }

        CategoryInfo getCategoryInfo( const LogCategory _logCategory )
        {
            LogCategory category = _logCategory.value() < m_categoryNames.size() ? _logCategory : LogCategory();
            const char* name = category.value() != kInvalidLogCategory ? m_categoryNames[category.value()].c_str() : "UnregisteredCategory";
            return { category, name };
        }

        UniqueRealizationContainer<ILogOutput> m_outputs;
        std::vector<std::string> m_categoryNames;
    };
}