
#pragma once

#include "Generator.hpp"

struct OutputData;

class TexGenerator : public Generator
{
public:
  bool generate(const String& engine, const OutputData& outputData, const String& outputFile);

  String getErrorString() const;

public:
  static const char* _defaultListingsLanguages[];
  static const usize _numOfDefaultListingsLanguages;

public:
  String generate(const OutputData::ParagraphSegment& segment) override;
  String generate(const OutputData::TitleSegment& segment) override;
  String generate(const OutputData::SeparatorSegment& segment) override;
  String generate(const OutputData::FigureSegment& segment) override;
  String generate(const OutputData::RuleSegment& segment) override;
  String generate(const OutputData::BulletListSegment& segment) override;
  String generate(const OutputData::NumberedListSegment& segment) override;
  String generate(const OutputData::BlockquoteSegment& segment) override;
  String generate(const OutputData::EnvironmentSegment& segment) override;
  String generate(const OutputData::TableSegment& segment) override;
  String generate(const OutputData::TexSegment& segment) override;
  String generate(const OutputData::TexPartSegment& segment) override;
  String generate(const OutputData::PdfSegment& segment) override;

  String escapeChar(uint32 c) override;
  String getSpanStart(const String& sequence) override;
  String getSpanEnd(const String& sequence) override;
  String getWordBreak(const char l, const char r) override;
  String getLink(const String& link, const String& name) override;
  String getLineBreak() override;
  String getInlineImage(const String& path) override;
  String getFootnote(const String& text) override;
  String getLatexFormula(const String& formula) override;

public:
  static String texTranslate(const String& str);
  static String getEnvironmentName(const String& language);
  static String getTexSize(const String& size, bool width = true);
};
