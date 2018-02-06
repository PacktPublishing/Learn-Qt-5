#include "xml-helper.h"

namespace cm {
namespace utilities {

QString XmlHelper::toString(const QDomNode& domNode)
{
	QString returnValue;
	for(auto i = 0; i < domNode.childNodes().size(); ++i) {
		QDomNode subNode = domNode.childNodes().at(i);
		appendNode(subNode, returnValue);
	}
	return returnValue;
}

void XmlHelper::appendNode(const QDomNode& domNode, QString& output)
{
	if(domNode.nodeType() == QDomNode::TextNode) {
		output.append(domNode.nodeValue());
		return;
	}

	if(domNode.nodeType() == QDomNode::AttributeNode) {
		output.append(" ");
		output.append(domNode.nodeName());
		output.append("=\"");
		output.append(domNode.nodeValue());
		output.append("\"");
		return;
	}

	if(domNode.nodeType() == QDomNode::ElementNode) {
		output.append("<");
		output.append(domNode.nodeName());
		// Add attributes
		for(auto i = 0; i < domNode.attributes().size(); ++i) {
			QDomNode subNode = domNode.attributes().item(i);
			appendNode(subNode, output);
		}
		output.append(">");
		for(auto i = 0; i < domNode.childNodes().size(); ++i) {
			QDomNode subNode = domNode.childNodes().at(i);
			appendNode(subNode, output);
		}
		output.append("</" + domNode.nodeName() + ">");
	}
}

}}
