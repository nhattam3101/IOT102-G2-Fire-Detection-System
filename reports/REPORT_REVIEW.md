# Final Report Review — IOT102 Group G2

## Deliverables

- `archive/drafts/IOT102_G2_FinalReport.tex`: retained IEEE-format manuscript draft with the existing FPT cover.
- `reports/markdown/freport.md`: revised Markdown source containing the same report claims, tables, references, AI declaration, and figure notes.
- The original `IOT102_G2_main_order_fixed.tex`, final firmware, and `docs/ai-audit/AI AuditLog.md` were not edited; the original manuscript is retained under `archive/drafts/`.

## Audit Findings and Fixes

- Replaced the working manuscript's generic `article` layout with the course template's `IEEEtran` layout.
- Removed excessive line-by-line paragraph fragmentation and condensed repeated material.
- Corrected the diagram paths used by the report source. The full-resolution exports now live under `docs/design/exports/`; the self-contained Overleaf package keeps upload-ready copies under `reports/overleaf/src/`.
- Enforced the requested order: Figure 1 block diagram, Table 1 hardware, Table 2 GPIO, Figure 2 schematic, Table 3 states, Figure 3 flowchart, Table 4 tests, and Figure 4 prototype placeholder.
- Added `placeins` barriers and bounded figure width/height while preserving aspect ratios.
- Reworked tables to fit one-column IEEE page width; the GPIO table uses paired device/GPIO columns.
- Verified that the final file contains one `\begin{document}` and one `\end{document}`, four figures, four tables, and eight traceable references.
- Aligned pins, thresholds, sensor polarity, buzzer behavior, servo angles, debounce, and retained-door behavior with `src/FireDetectionSingleFinal.ino`.
- Explicitly limited implemented scope to local processing. Wi-Fi, MQTT, Node-RED, Blynk, cloud/CSV logging, dashboards, and AI/ML are future extensions only.
- Recorded the team-reported 8/8 functional PASS result without converting it into a detection-accuracy claim or inventing quantitative measurements.
- Included the AI Usage Declaration while leaving the AI Audit Log as a separate deliverable. Blynk is correctly described as an IoT platform.

## Build and Page-Count Verification

- Static source validation: **PASS**. Environment nesting and brace counts are balanced; all three diagram files and the FPT logo exist.
- LaTeX compilation: **not performed** because `latexmk`, `pdflatex`, `xelatex`, `lualatex`, and `tectonic` are not installed in the available environment. Local Docker/Podman LaTeX fallback was unavailable because the container services are inaccessible under the workspace permissions.
- PDF review and exact page count: **not available** for the same reason. The course knowledge base states a 5–8 page IEEE report requirement, but the supplied materials do not clearly state whether the separate cover, references, and AI declaration are excluded. Therefore, page-limit compliance is not claimed.

## Remaining Technical and Submission TODOs

1. Add the final physical-prototype photograph as `src/prototype.png`; the manuscript will include it automatically. Until then, Figure 4 is an explicit placeholder.
2. Compile on Overleaf or a machine with a complete IEEE LaTeX installation, then inspect page count, figure legibility, float placement, and table alignment. If the full PDF exceeds the assigned counting rule, reduce figure heights or move the institutional cover to a separately submitted cover sheet rather than deleting evidence or limitations.
3. Verify the schematic against the assembled wiring and component part numbers. In particular, confirm the LM35 operating-voltage specification, buzzer rating, 5 V sensor-module digital output levels, LCD pull-up voltage, servo supply capacity, and common ground.
4. Preserve the reported 8/8 functional result, but attach photos/logs if available. Quantitative response time, calibration error, false-positive rate, false-negative rate, and long-term reliability remain unmeasured.
5. The firmware calls `updateDoor(danger)` twice in each loop. This does not contradict the reported state behavior, but it should be reviewed and reduced to one call in a future firmware revision to simplify debounce timing. The firmware was intentionally not modified in this report task.
6. The block diagram's cloud layer must remain visibly identified as proposed. The diagram also colors the boxes labelled “LED Red” and “LED Yellow” inconsistently; this cosmetic issue should be corrected in the source diagram before final visual submission if time permits.

## Source Conflicts Resolved

- Some knowledge-base and handover material describes an older configuration with a 45°C DANGER threshold and two buzzers. The final firmware instead uses 43°C and one active buzzer on GPIO15; the report follows the firmware.
- The canonical revised Markdown file is now `reports/markdown/freport.md`; the earlier root draft is retained as `archive/drafts/freport_legacy.md`.
