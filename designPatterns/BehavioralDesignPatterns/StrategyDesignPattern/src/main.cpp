#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>

/*
Markdown 
* asdfg
* asdfgh
...

Html
in html you need to have opening and closing statement,
however in both formats you essentially need to have add 
element functionality.
<ul>
    <li>adssfj</li>
</ul>

*/

enum class OutputFormat {
    markdown,
    html
};

struct ListStrategy {

    /*
    Start and end functions are not pure virtual while add_item 
    function is. This is to follow
    interface segregation principle.
    So essentially every single class which inherits from
    this one needs to have add_item function but not the start and end.
    They are required only for specific classes. 
    */
    virtual void start(std::ostringstream& oss) {}
    virtual void end(std::ostringstream& oss) {}
    virtual void add_item(std::ostringstream& oss, const std::string item) = 0;
};

struct MarkdownStrategy: ListStrategy {
    void add_item(std::ostringstream& oss, const std::string item) override {
        oss << "*" << item << std::endl;
    }
};

struct HtmlStrategy: ListStrategy {
    void start(std::ostringstream& oss) override {
        oss << "<ul>" << std::endl;
    }
    void end(std::ostringstream& oss) override {
        oss << "</ul>" << std::endl;
    }
    void add_item(std::ostringstream& oss, const std::string item) override {
        oss << "<li>" << item << "</li>" << std::endl;
    }
};

/**
 * @brief This struct is essentially for printing the formatted text easily. * 
 */
struct TextProcessor {

    void clear() {
        _oss.str("");
        _oss.clear();
    }
    void append_list(const std::vector<std::string>& items) {
        _strategy->start(_oss);
        for(const auto & item: items) {
            _strategy->add_item(_oss, item);
        } 
        _strategy->end(_oss);
    }
    void set_output_Format(const OutputFormat& format) {
        switch (format)
        {
        case OutputFormat::markdown:
            _strategy = std::make_unique<MarkdownStrategy>();
            break;
        case OutputFormat::html:
            _strategy = std::make_unique<HtmlStrategy>();
            break;
        }
    }
    std::string str() { return _oss.str(); }
    private:
        std::ostringstream _oss;
        std::unique_ptr<ListStrategy> _strategy;
};

template <typename T>
struct TextProcessorTemplated {
    void clear() {
        _oss.str("");
        _oss.clear();
    }
    void append_list(const std::vector<std::string>& items) {
        _strategy.start(_oss);
        for(const auto & item: items) {
            _strategy.add_item(_oss, item);
        } 
        _strategy.end(_oss);
    }
    std::string str() { return _oss.str(); }
    private:
        std::ostringstream _oss;
        T _strategy;
};


int main() {

    std::vector<std::string> items{"foo", "bar", "baz"};

    // Dynamic strategy, because you can change the strategy in runtime.
    TextProcessor tp;
    tp.set_output_Format(OutputFormat::markdown);
    tp.append_list(items);
    std::cout << tp.str() << std::endl;
    tp.clear();

    tp.set_output_Format(OutputFormat::html);
    tp.append_list(items);
    std::cout << tp.str() << std::endl;
    tp.clear();

    // static strategy

    TextProcessorTemplated<MarkdownStrategy> tpt_markdown;
    tpt_markdown.append_list(items);
    std::cout << tpt_markdown.str() << std::endl;
    tpt_markdown.clear();

    TextProcessorTemplated<HtmlStrategy> tpt_html;
    tpt_html.append_list(items);
    std::cout << tpt_html.str() << std::endl;
    tpt_html.clear();


    return 0;
}