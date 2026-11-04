# IOT102 G2 Final Report — Overleaf Package

## Package Contents

- `main.tex` — final `article` 12 pt A4 manuscript.
- `src/logofpt.png` — FPT logo used on the cover.
- `src/BlockDiagram_IOT102_G2-BlockDiagram.drawio.png` — system block diagram.
- `src/BlockDiagram_IOT102_G2-Circuit Schematic.drawio.png` — circuit schematic.
- `src/BlockDiagram_IOT102_G2-FlowChart.drawio.png` — firmware flowchart.

The package is self-contained. It contains no absolute machine path and does not depend on files outside `reports/overleaf/`.

## Changes Made

- Converted the Overleaf manuscript from `IEEEtran` to `\documentclass[12pt,a4paper]{article}` as requested.
- Applied A4 margins of 2 cm top/bottom and 2.5 cm left/right.
- Returned to the default LaTeX serif font used by the older article report; `newtxtext` and `newtxmath` are not loaded.
- Recreated the original cover proportions: centered 5 cm FPT logo, institutional headings, prominent project title, wide member table, instructor, city, and date.
- Kept exactly one `titlepage`. There is no `\maketitle` or repeated project title before the abstract.
- Rendered keywords as a normal bold label because `IEEEkeywords` is specific to IEEEtran.
- Separated Introduction and Related Work into the requested section order without changing their academic claims.
- Kept one-column 12 pt body text with restrained paragraph and float spacing.
- Used `tabularx` for content tables so text wraps inside the A4 text area. Only the dense functional-test table uses `\small`.
- Kept all figures and tables in the required order and inserted `\FloatBarrier` after major floats.
- Sized the block diagram, circuit schematic, and vertical flowchart independently while preserving aspect ratios.
- Changed every real image lookup to the Overleaf-relative `src/` directory.
- Protected the Circuit Schematic filename, which contains a space, using `\detokenize{...}`.
- Retained only the prototype placeholder because no physical-prototype photograph was supplied.

The technical content, GPIO assignments, 40/43°C thresholds, SAFE/WARNING/DANGER logic, eight functional test results, eight references, author contributions, and AI declaration were preserved. The firmware and AI Audit Log were not modified.

## Uploading to Overleaf

1. Create a blank Overleaf project.
2. Upload the **contents** of `reports/overleaf/`, preserving the `src/` subfolder. Uploading the complete folder as a ZIP is also suitable.
3. Set `main.tex` as the Main document.
4. Select pdfLaTeX and compile twice so figure/table references and citations are resolved.

The source uses packages included in a normal Overleaf TeX Live installation: `graphicx`, `array`, `geometry`, `placeins`, `booktabs`, `amsmath`, `amssymb`, `microtype`, `cite`, `tabularx`, `url`, and `hyperref`.

## Verification Status

- Static LaTeX structure: **passed**. Environment nesting and braces are balanced.
- Image verification: **passed**. The logo and all three diagrams exist in `src/`; filenames and case match `main.tex`.
- Cross-reference verification: **passed**. Citation/bibliography keys and label/reference keys match.
- Duplicate-title check: **passed**. One cover, no active `\maketitle`, one `\end{document}`.
- Local PDF compilation: **not performed**. The environment has no `latexmk`, `pdflatex`, `xelatex`, `lualatex`, or `tectonic`; accessible Docker/Podman LaTeX fallback is also unavailable.
- Page count: **not available**. Compliance with the course's 5–8 page limit cannot be confirmed locally.

## Remaining TODOs

1. Add the real prototype photograph as `src/prototype.png`; the conditional LaTeX block will replace the placeholder automatically.
2. Compile twice on Overleaf and inspect the exact page count, table wrapping, float positions, and small labels in the raster diagrams.
3. The course template and knowledge base identify IEEE formatting as the official target, while this package intentionally follows the requested legacy `article` design. Confirm that the instructor accepts this format before final submission.
4. If the report exceeds the assigned page limit, first reduce the three diagram height limits slightly. Do not remove limitations, references, test qualifications, or the AI declaration.
5. Vector PDF exports from draw.io would improve small-label sharpness, especially for the circuit schematic and flowchart, if those assets become available.
