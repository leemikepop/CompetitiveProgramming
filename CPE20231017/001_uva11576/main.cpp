//Uva 11576
/*
https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/11576.pdf
*/

#include <iostream>
#include <sstream>
#include <string>
//#include <bits/stdc++.h>

using namespace std;

int main(){
    clock_t start = clock();
    ostringstream oss;

    int n;
    cin >> n;
    while (n--) {
        int k, w, ans;
        cin >> k >> w;
        cin.ignore();
        ans = k*w;
        string lines[2];
        getline(cin, lines[0]);
        bool curr = true;        
        for(int i = 1; i < w; ++i){ //read w lines
            getline(cin, lines[curr]);
            for(int j = 0; j < k; ++j){ //iterate width of the sign
                int l;
                for(l = 0; (j + l < k) && (lines[curr][l] == lines[!curr][j+l]); ++l)
                	continue;
                if(j+l==k){
                    ans -= (k-j);
                    break;
                }
            }
            curr = !curr;
        }
        oss << ans << endl;
    }
    
    cout << oss.str();
    clock_t end = clock();
    double duration = (double)(end - start) / (__clock_t)1000;
    cout << endl << "Exicution Time: " << duration << " ms" << endl;
    return 0;
}
/*
2
3 2
CAT
TED
3 3
CAT
ATE
TEA
*/

/*https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/testData/uva11576a.php
21
3 2
CAT
TED
3 3
CAT
ATE
TEA
3 3
TEA
CAT
ATE
6 1
ABABAB
6 2
ABABAB
ABABAB
6 3
ABABAB
ABABAB
ABABAB
9 1
OCMUCWZWU
1 6
A
A
B
B
B
C
22 2
EMZVZMTELPCURJUZFDDUBX
TELPCURJUZFDDUBXLIQILV
37 3
RXGPERIZFDRXUEOGGWSBRNZEHGMMGXBXQVVAL
NZEHGMMGXBXQVVALRPGWBIDPNKLLGNZUSFRDS
LRPGWBIDPNKLLGNZUSFRDSZAUIXIPUTWQSGAI
10 5
DCACDDDBBC
CACDDDBBCA
DDBBCABDDB
BCABDDBABC
DBABCDDBBA
10 20
GZGJUFBLPK
ZGJUFBLPKN
BLPKNQJQBW
NQJQBWTHCV
QJQBWTHCVR
BWTHCVREWZ
BWTHCVREWZ
REWZJCSMKD
REWZJCSMKD
WZJCSMKDJC
ZJCSMKDJCN
ZJCSMKDJCN
CSMKDJCNPM
NPMMEZGCLV
LVKQNZOAIG
QNZOAIGTHF
GTHFNMNVIC
FNMNVICZHO
ICZHOJCGSJ
CGSJUISSFZ
42 21
FCPKOOTUCOJUCTOTIHTNATSFWGSLACKJWLHWTMUIBC
TNATSFWGSLACKJWLHWTMUIBCQKUVBVWDYDIPFMIQGD
ATSFWGSLACKJWLHWTMUIBCQKUVBVWDYDIPFMIQGDIF
JWLHWTMUIBCQKUVBVWDYDIPFMIQGDIFXBJVOXHMUBE
RVUMYBBYVAUZVAVYAPEFEAVOIUBQAAAVWNEISGXZTQ
UMYBBYVAUZVAVYAPEFEAVOIUBQAAAVWNEISGXZTQEH
AUZVAVYAPEFEAVOIUBQAAAVWNEISGXZTQEHWZENZWV
ZTQEHWZENZWVXSFLJYBVUKIKTHJWMFOHONGSTNUQUI
HJWMFOHONGSTNUQUIXYYHFLCMNLGMNDCIVUXLGAILH
CIVUXLGAILHPHKXSOYROQUGOPOFTXHLKETGRUACJDJ
SOYROQUGOPOFTXHLKETGRUACJDJWMXHOMIQKMICAXG
ACJDJWMXHOMIQKMICAXGQMLNAKOIFLBXKVWHXZOQNJ
VWHXZOQNJIQICYXOHZTGXKRMGDSKMXUTRPKYMUTHRL
ICYXOHZTGXKRMGDSKMXUTRPKYMUTHRLSZVDFHGFFXF
GFFXFKNBSOIMTHRSTCJRLKDJKAJHVNPXCRKGSYKZOJ
SYKZOJSVSJRQAWQXPEICQUZMBDOXANTWXIOUCQGWDL
SVSJRQAWQXPEICQUZMBDOXANTWXIOUCQGWDLAZPFHI
SVSJRQAWQXPEICQUZMBDOXANTWXIOUCQGWDLAZPFHI
DOXANTWXIOUCQGWDLAZPFHIXPWDZSOZAYLDFGBXLCF
CFUXKEIZOAQLBSCOPYWVZIBVDMOZADGNTFANEQYSBB
LBSCOPYWVZIBVDMOZADGNTFANEQYSBBTILUXAVIWRZ
10 36
HYYTDNXZBN
JMNZPDSDEY
YJECBNWFNV
ECBNWFNVRJ
VRJSGKDSOW
SGKDSOWKXA
DSOWKXAHIO
WKXAHIOLYA
YAXPFXRYQV
LAYEMZZJEA
ZJEAGZBAML
GZBAMLJQNQ
MLJQNQXLPO
QNQXLPOQRU
UOALSMQBWU
WUHJYFQZRY
QZRYTPSXAU
RYTPSXAUNU
SXAUNUVVTY
YCKYGENPVP
ENPVPDYGLG
DYGLGYHGIM
LGYHGIMRUM
IBZLEHXZUW
LEHXZUWVDJ
HXZUWVDJPM
VDJPMMNODP
JPMMNODPEU
JPMMNODPEU
AROUWOEMLJ
MLJDJCWJAD
DJCWJADTKB
WJADTKBVGB
DTKBVGBVUB
VUBQVQPBGZ
QPBGZEXHQY
22 58
VECYZDBYCSBZDGZHPUSVTQ
BZDGZHPUSVTQGAMSDLSION
NXDQVMYIXWKSRBZFQNOAFX
KSRBZFQNOAFXFLGKVMEDZX
EDZXDQTGHNDHNJWNPLTYQS
DHNJWNPLTYQSZLOCYFTXQT
CDNTODZHYJJQDAMHKXFZCY
CYQYBSIFELELYXVTNCXBLY
YBSIFELELYXVTNCXBLYTMW
VTNCXBLYTMWWILDOVXJNEL
ELZNEJTDJKDNIDOFDWGTEY
ELZNEJTDJKDNIDOFDWGTEY
DNIDOFDWGTEYTABWUTWZAL
ABWUTWZALVRYPKDZYBYGHM
TWZALVRYPKDZYBYGHMEQCX
DQGIHBXQUOOZSPHJYHKHKZ
HJYHKHKZXTFHNCESQPVFXC
XCAVIXSIFKZGNDGOWLQCRF
FSODRAXNWUJOCKXOFEZLGX
OFEZLGXAOQHLWFDUQUFALR
QHLWFDUQUFALRYVSNKCWLM
LRYVSNKCWLMREQNLHJHUKI
REQNLHJHUKIGVAFJMTAWZJ
IGVAFJMTAWZJTAYRETOBQH
TAWZJTAYRETOBQHCQYTHVW
AYRETOBQHCQYTHVWUCADFO
TOBQHCQYTHVWUCADFODWYH
TOBQHCQYTHVWUCADFODWYH
WYHBBDAAZPFAUFUDUVWGSS
FUDUVWGSSZWDOKDGJZMVUW
WDHXWYVWYMSATNXUQNVLUJ
VLUJGGDCYWXZJGKVXNCXNO
NCXNOXIXSIDEGJLLJNVVUH
IDEGJLLJNVVUHPQLBAVDES
EGJLLJNVVUHPQLBAVDESRD
LBAVDESRDLOIBRZJLGPBLB
SRDLOIBRZJLGPBLBAWKVLW
LBAWKVLWAFCONNXTQFLLGC
AFCONNXTQFLLGCRRIKXWZV
IKXWZVGDZYQSIXHJUMSTFI
XHJUMSTFIGUNAVNRLOFJNA
LOFJNATWNGIHRQYIWSUHXC
ATWNGIHRQYIWSUHXCDESHI
NGIHRQYIWSUHXCDESHIRSK
RQYIWSUHXCDESHIRSKAONS
UHXCDESHIRSKAONSKLKKHY
KHYQAPOEYFPVZEWNJOYIQB
FPVZEWNJOYIQBDFVNCGSVK
NJOYIQBDFVNCGSVKJBLUPJ
FVNCGSVKJBLUPJYOOJNBHA
SVKJBLUPJYOOJNBHAWUMPU
PJYOOJNBHAWUMPUJOPMEBO
AUNKZAPPVGQLPTROLUHFIO
IOSBIVATCLIPBFTWYESRVZ
RVZQLUDONCBLDOXBUPCFQV
CFQVJJGPUVFNUXCJAJTHQB
FNUXCJAJTHQBDAZRRGSPMO
NUXCJAJTHQBDAZRRGSPMOT
67 37
WDEPYENVGZLJLSHSKYNLBPKQKSIRFRQZXKIYWZVSFBNSQHLQTPNIXPEUDZIXTMWDHQO
WDEPYENVGZLJLSHSKYNLBPKQKSIRFRQZXKIYWZVSFBNSQHLQTPNIXPEUDZIXTMWDHQO
YNLBPKQKSIRFRQZXKIYWZVSFBNSQHLQTPNIXPEUDZIXTMWDHQOOZBFUXDSWFVNQVPRJ
YWZVSFBNSQHLQTPNIXPEUDZIXTMWDHQOOZBFUXDSWFVNQVPRJXWPCWATMLKBIWJIQUE
FUXDSWFVNQVPRJXWPCWATMLKBIWJIQUENXSQBNZCAQMPWOJEEEDOGTUBFRRKJUMIYWP
ENXSQBNZCAQMPWOJEEEDOGTUBFRRKJUMIYWPAVFRJDHIASAYYRMDZQKLUJDTAYXNUCO
YWPAVFRJDHIASAYYRMDZQKLUJDTAYXNUCOAQJGAIEFOYABFPICNZNIAJNCAIMIGFHUK
UKJKUDKAJEFQYHXQXZWWQTVYWCOLYWAYVHUGAPESROPJDRCDYRYLVAQQBVTIANMYCSZ
LVAQQBVTIANMYCSZFYYQDYOWKRCPVAKSZMBEZFVEIKMZULKVPVBFADGSQOCTQOKGAZI
BVTIANMYCSZFYYQDYOWKRCPVAKSZMBEZFVEIKMZULKVPVBFADGSQOCTQOKGAZIPTPAU
ZIPTPAUXSDFMISMZWFFUAITFNVVKKSLJRMLIHNTKPAIYGXQQLOCJFTFXLXTCULPYGEP
MISMZWFFUAITFNVVKKSLJRMLIHNTKPAIYGXQQLOCJFTFXLXTCULPYGEPDCZKNJBGITZ
IHNTKPAIYGXQQLOCJFTFXLXTCULPYGEPDCZKNJBGITZFWGCBAROYJUXHCTFOFSZACQJ
JBGITZFWGCBAROYJUXHCTFOFSZACQJOGPNZPBDFXCVAQCZVXNSKYWKZRJMLFRILORRF
QJOGPNZPBDFXCVAQCZVXNSKYWKZRJMLFRILORRFZVBOJXRJRBQRDRQBBTHSVEKAZPBC
WKZRJMLFRILORRFZVBOJXRJRBQRDRQBBTHSVEKAZPBCGONLHVYJPURHZJFXCUPIXDCQ
YJPURHZJFXCUPIXDCQNHOAWPTZNDSGGLRHXDQMLDEQIQMEWIWPAGMHYTWMUJESIGULB
EWIWPAGMHYTWMUJESIGULBQYNKTCZCVFPECLKDSHKQSSOGDPRUVHZRESWKGODUQVSVA
SVAHHUJTZWVNIJEBEJVDGBEBGODXTQBFLEKPMOBNYDJZWZOCSHAPXWOJMQJBLSFCWLT
DJZWZOCSHAPXWOJMQJBLSFCWLTNVJLDCNSKYTMDHRZFISGLXXCUQHFDMNTZMTIGNLUX
OJMQJBLSFCWLTNVJLDCNSKYTMDHRZFISGLXXCUQHFDMNTZMTIGNLUXGDLKXXLUWLEPC
NTZMTIGNLUXGDLKXXLUWLEPCRVKSQGLTPKKCISCKVHOHEFCKDDTPPVDIUJIWKOSCTGA
CTGAEZXDZLPUVVCZYAONDSAWBMKUMWYIDDQGVQNAGEHPAFHNPNDXVQADHIMFODKSXGD
XVQADHIMFODKSXGDSOLVAKEHUZWXEWHHFZGTKCOMQXAPHUIMNXTXRUEJEKRTNYJBBCE
HHFZGTKCOMQXAPHUIMNXTXRUEJEKRTNYJBBCESJWXAZYXEPWFDCZTYNJMQFBDXAFPJF
AZYXEPWFDCZTYNJMQFBDXAFPJFKKYJMGLGWTDOTMJSGANUZQWLGPNXFHDFNUUPLRNNG
TYNJMQFBDXAFPJFKKYJMGLGWTDOTMJSGANUZQWLGPNXFHDFNUUPLRNNGCXSLREKCIAA
PLRNNGCXSLREKCIAAVZQIGCTDNPPSNCNQCPTIKVNOSEXTHMGKCWXPSUSRQAXBUANKIL
QAXBUANKILHGWYEFXJISAZAFYFMWFVLCRJFDZJOTRPVFPXNTOIGYWKYZAASFUOSAHFO
GWYEFXJISAZAFYFMWFVLCRJFDZJOTRPVFPXNTOIGYWKYZAASFUOSAHFOFPYYLGOQKKD
ZAASFUOSAHFOFPYYLGOQKKDNNWPHYRMABSCGLJCIZKJQVKHGEZQQUOZAWXWQKDOUNHP
VKHGEZQQUOZAWXWQKDOUNHPYHOXTRILUVFLMQBYTCRDRGJELQTZGXTVENUFAEIYCIUK
ZGXTVENUFAEIYCIUKWYKOPYTLWNEFNMVCIWZPAFPOSQVUXFOQYVYYAHLNIJIENBSJFM
PAFPOSQVUXFOQYVYYAHLNIJIENBSJFMETWLXQLBMGZZMYULDDGAFZDUNNACYYDKHXYW
FPOSQVUXFOQYVYYAHLNIJIENBSJFMETWLXQLBMGZZMYULDDGAFZDUNNACYYDKHXYWFB
MYULDDGAFZDUNNACYYDKHXYWFBIBMPKOPQHRZEGRKANLPZHANKXZYZPGDGMCJZXGQRU
SGBCAZOXODSUQKTCQJSBRRQDUPEGZSFGHCGXFKLSAAVPXIZAWGXEWAVUBYSIENOMSNE
11 35
IWDRDAJQZVH
AJQZVHPUKSQ
ZVHPUKSQMTI
UKSQMTIWLQD
SQMTIWLQDXW
SQMTIWLQDXW
IWLQDXWCEQZ
CEQZVZMCKAC
VZMCKACVHVY
HVYZZLYPAKW
ZLYPAKWMPJQ
PVNMXHKKWRF
MXHKKWRFFCV
RFFCVJZTJAS
CBQBFUSEMMB
BFUSEMMBWOI
MBWOIBXTVBA
MBWOIBXTVBA
BAFNYDAHXHX
HXFVHMOLDGE
HMOLDGEBKYZ
EBKYZBMBZZE
ZEAYMUJYNDW
WZHAZSOAAGL
SOAAGLGYNNN
OAAGLGYNNNB
GYNNNBJFMYJ
YNNNBJFMYJH
BJFMYJHCXTK
KGTYXEYISLC
YXEYISLCXPM
CXPMWZUSIGQ
SIGQPKGSGHO
IGQPKGSGHOZ
GHOZNSOQNKZ
54 35
KTOCUNYXUCCQPZIHFNAUXVIOWZZJMBTKTWQGPOLGTJDJLBLEXWIIBW
BTKTWQGPOLGTJDJLBLEXWIIBWKYRUECXKUVBADCBDTINDAZZATKRLB
ADCBDTINDAZZATKRLBLLSUNHJVPZQNSNVNCWWXBJTLDJOZNGGVZVGD
TKRLBLLSUNHJVPZQNSNVNCWWXBJTLDJOZNGGVZVGDQBETVXPMMLLSG
LLSGLAOLTUPAUNOEAPYYPBAKDCLKSSKNDIULTGOSKVCREDJYZZVEND
LLSGLAOLTUPAUNOEAPYYPBAKDCLKSSKNDIULTGOSKVCREDJYZZVEND
PAUNOEAPYYPBAKDCLKSSKNDIULTGOSKVCREDJYZZVENDMPGMVDVBQA
ENDMPGMVDVBQALWFYXOQMHZXVGYBDNGYHCBBXUTFTBCXGVBOVJDWQB
DMPGMVDVBQALWFYXOQMHZXVGYBDNGYHCBBXUTFTBCXGVBOVJDWQBSG
BXUTFTBCXGVBOVJDWQBSGQEEGFPOYLQLHTSDCDFTNUJRCHBXBAJUIB
QLHTSDCDFTNUJRCHBXBAJUIBNNUUKNOKLGFUDSKQBQJGZERYCYYVPC
CRULBNVZLJAIBRTRGSBZQKMUOAPQDNKJVQVALCLKXLJAJMFSLSZCBC
KJVQVALCLKXLJAJMFSLSZCBCMGVKTRHVSFYVTMRLCDAJAAYOJXYTJE
EIKCAFPKKDGFNTQTVBOCWPGNTBKDVGLGEUCXEYOPGIZSPMOYUCBEIS
KDVGLGEUCXEYOPGIZSPMOYUCBEISEMYSYETJCYOQUABIWPQAJXBMON
YSYETJCYOQUABIWPQAJXBMONGUFTSSPEYLWTVCVBCFFTBKARFUDTDE
PEYLWTVCVBCFFTBKARFUDTDEGUYOULVNXJNOWMPCUEFXYUTHQVLQCK
HQVLQCKOITQYDEHYMDDQZIOOJVXZPQXYZQUUGGXBHSZDEFRKCJHWAW
EHYMDDQZIOOJVXZPQXYZQUUGGXBHSZDEFRKCJHWAWUSJKEWRCTWHYA
CTWHYAZIFNFITTFRYXOLQSFZWAQVROERLZTWVNJROKINGNMNSFKLTL
FITTFRYXOLQSFZWAQVROERLZTWVNJROKINGNMNSFKLTLTZHPASTENH
NHZDWSPHPLQMXTDLTSNNSKWPRUMNFYGPJLZFLVRWTXCOWHYGRTJIFY
LZFLVRWTXCOWHYGRTJIFYLHDJGZAHVMESWIGAVHVIOAZCRULLWFWJB
ZFLVRWTXCOWHYGRTJIFYLHDJGZAHVMESWIGAVHVIOAZCRULLWFWJBH
ZAHVMESWIGAVHVIOAZCRULLWFWJBHTHZKUULALQOKRPOWLEJIDRPLH
EJIDRPLHZOLBDFKZVZEILGLKYQMEAYTBFHUCYFAFQHCHWEKTGQDOZQ
KZVZEILGLKYQMEAYTBFHUCYFAFQHCHWEKTGQDOZQQBKBCWHAIXBEMG
WEKTGQDOZQQBKBCWHAIXBEMGESPFKVZPWFXKVNYQGDIZUXSLPPDNRO
WFXKVNYQGDIZUXSLPPDNROABSWJFMGZWMWZVVICGARKKYYAEDJBGXW
WFXKVNYQGDIZUXSLPPDNROABSWJFMGZWMWZVVICGARKKYYAEDJBGXW
IZUXSLPPDNROABSWJFMGZWMWZVVICGARKKYYAEDJBGXWOUFRRKDFCB
BHUVWICSXJQAYLBBWZQZTDWHBTOLVKVOGJPZLMLXJNUGETOGGOEKIJ
UVWICSXJQAYLBBWZQZTDWHBTOLVKVOGJPZLMLXJNUGETOGGOEKIJVB
WHBTOLVKVOGJPZLMLXJNUGETOGGOEKIJVBBMXWGNIYFIJLKJKBGQGF
QHLVSWCEOHFFPSNCABMBBGJXFYWKTEDNBXJGQFXQFKDDBEGWQLAXOI
20 68
KCTDYIWZDXUVRFJQKRZS
AOZEAAPVQXDJUKFLHBVR
KFLHBVRRTEXVHJNHQWPI
LHBVRRTEXVHJNHQWPIDL
QWPIDLIRUQBUPYRAAJKP
MUIAWVDZKBNGPGXLRXJZ
LRXJZGRTUNWYSLBJAQAX
AQAXEGAOXRCXQYIFYGPK
QAXEGAOXRCXQYIFYGPKY
GPKYHXJSZZIVHQQMPSQV
GPKYHXJSZZIVHQQMPSQV
ZIVHQQMPSQVWFWFFJMFN
SQVWFWFFJMFNKNHUCIXE
WFFJMFNKNHUCIXEMHWIL
CIXEMHWILLRMSKZXBKJI
CIXEMHWILLRMSKZXBKJI
ZXBKJIZUXTJULSXQVMFR
QVMFRBXQBJECPALAGNAJ
GNAJOAMFWPOKSYKFBBDF
KFBBDFEYDGWYDHPVBRJZ
EQKLVRYSGCRBFXDKTGWX
SGCRBFXDKTGWXLLPYHHM
BFXDKTGWXLLPYHHMFPDK
HHMFPDKAQFVZETORNWMP
MPEBZPZFJOEDMAVUGXFX
MEADDJYUMJEDHVWXNJHT
MEADDJYUMJEDHVWXNJHT
JEDHVWXNJHTNYIMJHEBP
HVWXNJHTNYIMJHEBPJGB
NYIMJHEBPJGBBOCMYIIL
HEBPJGBBOCMYIILJRPTA
RPTARZGHLJLHTGXGYYTE
LHTGXGYYTEHBJOFOCOHD
GXGYYTEHBJOFOCOHDSGJ
HDSGJIAVYHQAGODGQHDD
DDUFINPICLMKXKMXDWWU
DDUFINPICLMKXKMXDWWU
NPICLMKXKMXDWWUEBZYQ
BZYQPXPDDZOKRMDFUHAA
AAPVVXJJDAFIFJWLGHVS
VVXJJDAFIFJWLGHVSANE
JDAFIFJWLGHVSANEUUYT
JDAFIFJWLGHVSANEUUYT
EUUYTKLPSNZBKPBKDTUX
SNZBKPBKDTUXRYBOJWOQ
UXRYBOJWOQSOZAIDXXBP
AIDXXBPNJYBHWERGLNUQ
NUQRHRNKOVYYPWDOLNFL
YYPWDOLNFLKTHXTVTLPI
KTHXTVTLPIGAVDEUWUEC
DEUWUECKIGQILCTCJMRB
CTCJMRBJDCONMYXXXRPN
ONMYXXXRPNJIETYDBHQG
NMYXXXRPNJIETYDBHQGH
GHNSHFXPZOUVFLQEYGDO
OUVFLQEYGDOPPJEIELLR
UVFLQEYGDOPPJEIELLRM
LQEYGDOPPJEIELLRMKGN
HXKAVURANIECHJMVUHUM
JMVUHUMZCGBLAYQGZDPP
UMZCGBLAYQGZDPPQFLVS
LAYQGZDPPQFLVSLQTARS
PQFLVSLQTARSYYBDBKWW
PQFLVSLQTARSYYBDBKWW
QHUALOEZNNZUYRFDSKQZ
ZNNZUYRFDSKQZUHSMDTS
ZUYRFDSKQZUHSMDTSYRQ
QMSYDPWYLVMQLTEOQIAU
10 40
EURBGOAPVJ
JKELEKBSRT
RTNPIOYNFJ
OYNFJVXMVK
XMVKHXXBST
YDTWTIHPRD
TWTIHPRDQH
WTIHPRDQHC
PRDQHCOAMJ
JDMDPEWDIA
DIAXAIEUXK
KXHKZOLXWX
LXWXDPNMUL
MULXOXQUND
DLRPPNZZQS
VNZYFDNAZN
DNAZNMPRKJ
ZNMPRKJIPU
JBSRRGMOLA
RGMOLAZSAS
GMOLAZSASP
PVFPFXVNDL
PFXVNDLKJQ
QNEYRJCCFP
CCFPVFJJRB
RBXCSYAOFX
CSYAOFXIJT
OFXIJTHIHZ
CXYSKQWZYG
WZYGUUJRYN
ZYGUUJRYNK
JRYNKYHJIN
NNJVKRKPNS
KPNSSNFJKK
SSNFJKKPLK
KRTOTKSLXJ
SLXJJZUUHC
ZUUHCCIGVF
UUHCCIGVFK
IGVFKPIYFU
68 13
QAVCDSXAOHLIQUULONDZXYNTWRBVBGEKFMKOOXALBGWRRHTFHZNBAGBPWIOGRLRTMBWJ
AGBPWIOGRLRTMBWJQVLBBWWAEXHREMHTCDGAUFPGLVQLOICLVKDAWETWUBBCKSCVZDUE
SCVZDUEWNYUTVNQEOSUXQLCXQRCUBHESHHZFUNMTINJOXSHGIUHAGININCGMFXRPSKYY
DUEWNYUTVNQEOSUXQLCXQRCUBHESHHZFUNMTINJOXSHGIUHAGININCGMFXRPSKYYIDOM
INCGMFXRPSKYYIDOMDHDJVGBENSQIHJWNPHQKBGHUCYQFCRKLNVAROTREWWCUCJZCQHG
WSWMVTOZEOQTOKAWXJCEMRCXBSMDDEEWJZHHGITUGKCWUJVHZGPCZVAGCBMDVHGOKRRY
CBMDVHGOKRRYCRJMCYIOPOITSBSCHCDEXAIMGDXDRLPQEFCCAXASNOKMXYTQFUIZVTDE
CRJMCYIOPOITSBSCHCDEXAIMGDXDRLPQEFCCAXASNOKMXYTQFUIZVTDEIXTVKNWPVNEW
ITSBSCHCDEXAIMGDXDRLPQEFCCAXASNOKMXYTQFUIZVTDEIXTVKNWPVNEWZXEYBTJTUU
NWPVNEWZXEYBTJTUUKLLHHZDXBUIBEUNTFILOVXDXVHFGRXBYSHTFLWHAWJIAUDMVYCF
WHAWJIAUDMVYCFYAKZGRLUZUWHPAXVWDZIBHXMZROVFROUONLQPYRBMZYRGNLKJWHJDQ
ROUONLQPYRBMZYRGNLKJWHJDQSTVJAPDXVGHKSNUQNIISXMDIKPELWZLHJCHAAGZSZHI
IISXMDIKPELWZLHJCHAAGZSZHIADGSUTKLQGZTFGUJSERLHLXVOCBLTWZSXATRVARZPJ
*/

/*https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/testData/uva11576b.php
18
4 7
WEAB
MYIC
CBBG
CBBG
BGLE
GLET
GLET
12 2
MKHGRBXWNUEF
KHGRBXWNUEFQ
12 3
UEFQXDGGWRXO
FQXDGGWRXOLK
DGGWRXOLKRSD
10 5
SAODJWWOGW
TVJRNLZXBI
NLZXBIWOUU
UCBFOIMFHG
GVDVOJVVKX
12 5
JAWEPKWEEDDI
DDIWXTYBLFUA
UAWLDSGCYTJG
TJGZZMAMWIZK
ZKXDNGVBERCY
12 9
NGVBERCYXRJA
BERCYXRJANAX
RCYXRJANAXHJ
XRJANAXHJRZF
JRZFXCERSXPZ
JRZFXCERSXPZ
SXPZETLPJYZV
SXPZETLPJYZV
XPZETLPJYZVX
15 12
BOBYKSGCRGOQNNS
BOBYKSGCRGOQNNS
BOBYKSGCRGOQNNS
CRGOQNNSOZJJCYC
OQNNSOZJJCYCTKM
OQNNSOZJJCYCTKM
ZJJCYCTKMEJPLPS
KMEJPLPSWQOJWUY
JWUYNSFDGSKGFEM
SFDGSKGFEMPPPIV
SFDGSKGFEMPPPIV
FDGSKGFEMPPPIVW
40 53
KVDFKFERYRVXLIFSRYWCNZXFSJUDPGATWQDRCQJM
JUDPGATWQDRCQJMWUDOXXKCEUNDDOZLYSLBXFLTM
LYSLBXFLTMRUUQXNGPPBGOFZYJASAIQQBHRNGBNJ
RNGBNJXULFJDBUDCWTUOPFVHGPXSOODWEQXABQOS
TUOPFVHGPXSOODWEQXABQOSCZRQDCABMFECTSTOR
QXABQOSCZRQDCABMFECTSTORLVSXTURQNUYRYJSJ
QOSCZRQDCABMFECTSTORLVSXTURQNUYRYJSJQUYF
TSTORLVSXTURQNUYRYJSJQUYFMOUGNEPIYDHJOXD
YFMOUGNEPIYDHJOXDZMDERGBTSNAWGZASFKCIFBB
WGZASFKCIFBBGQSEWMGRINPYKZQJBGGLOJVKBYBI
ZASFKCIFBBGQSEWMGRINPYKZQJBGGLOJVKBYBIHQ
MGRINPYKZQJBGGLOJVKBYBIHQUUOVLQDYNEEXCIH
LOJVKBYBIHQUUOVLQDYNEEXCIHKOCYNUWLCZLHNM
HNMYKRBFTKALOAIDUCGCWKFJFRXXLVEIISSISEFS
CGCWKFJFRXXLVEIISSISEFSVKIWSINPNHCBOUDRD
FSVKIWSINPNHCBOUDRDJRULHOZPJXJNCAPNDPLWN
UDRDJRULHOZPJXJNCAPNDPLWNNCWCVPCOULREMLJ
RULHOZPJXJNCAPNDPLWNNCWCVPCOULREMLJRVKLM
NCWCVPCOULREMLJRVKLMODNBVTJDTWEZYOYCQKNX
JDTWEZYOYCQKNXNYJBIXDNEHETKKKPLLAUUMJWNW
QKNXNYJBIXDNEHETKKKPLLAUUMJWNWVYPQYCNPGY
YPQYCNPGYBVDXXFQCNVBJDQPXSDYTNDJYSZENYIR
CNVBJDQPXSDYTNDJYSZENYIRHZATCOANXJLMELYK
KZHBUDGMUZOWTNYNKVCBPHUMRAPQBBPFSCTXKRES
BPHUMRAPQBBPFSCTXKRESPXTAESMCXBBFAGVDWWY
FSCTXKRESPXTAESMCXBBFAGVDWWYBFAQSIHULWHC
FSCTXKRESPXTAESMCXBBFAGVDWWYBFAQSIHULWHC
IHULWHCDLBMGAXZIBSCNNUVDYIIVRFNCOWXSWFZH
DLBMGAXZIBSCNNUVDYIIVRFNCOWXSWFZHYGEICPC
COWXSWFZHYGEICPCBAQADVRLIMRVOLJMXDEUIRGZ
IMRVOLJMXDEUIRGZCDGGNRDNXZUIRWCZVGXKLNZS
UIRGZCDGGNRDNXZUIRWCZVGXKLNZSYQPPHTSNGBK
XZUIRWCZVGXKLNZSYQPPHTSNGBKBOQJZDHFGMMDR
DRCMRISJHOFYVUWMGAHARPFLYEMARNAPYWBNFHKO
RISJHOFYVUWMGAHARPFLYEMARNAPYWBNFHKOBKRG
MGAHARPFLYEMARNAPYWBNFHKOBKRGYSFVYGUHYOV
VYGUHYOVIKFGZELEJVCFLPGYJBSPXUCLGLBSNCKA
PGHJERUXANFBIOPJCVEUJSGXXQYXNQOJPESSFGSB
UJSGXXQYXNQOJPESSFGSBDDLVTWVYMXUWNJQBIPM
SFGSBDDLVTWVYMXUWNJQBIPMVEDRCZNVNKQIJJGW
NJQBIPMVEDRCZNVNKQIJJGWIUEFUZEXPGFIWYBTL
VNKQIJJGWIUEFUZEXPGFIWYBTLMDILTOQWQDSQUC
UCDKHTPSLSJLKTOPHKGELQTYFAEDUYSDCELCLNJD
NJDOFSWCUSVXVFMVSIWRPPBVYADFZUMAHKFIDNYQ
CUSVXVFMVSIWRPPBVYADFZUMAHKFIDNYQEDACROG
HKFIDNYQEDACROGRPRVAZVPHJMIQAGUEQGSHVLVE
HVLVEKZQXNZIPBTYZOIYOBQTJAKALOJIRZBTFHYI
BTFHYIHRUHHSOIPFGCPJYYZUIQIHUQSOHOIHURCO
OZEGBRTVKPAAZGGIAASLZCYCQFSHRJDPOSLLSXFC
SHRJDPOSLLSXFCGKCPSOTHVPHQGVXGXXIIFPREEG
DPOSLLSXFCGKCPSOTHVPHQGVXGXXIIFPREEGLEUQ
LLSXFCGKCPSOTHVPHQGVXGXXIIFPREEGLEUQORUU
EUQORUURKMYSSTHKZOONDEMABMEHDIRGEEWJAJVC
13 17
XYIOTZRMHWOMT
OTZRMHWOMTFOM
MIKQFFHVAUIEC
VAUIECQQDTKDG
KDGHIMCGGGTIQ
IMCGGGTIQPWXW
PWXWXKLWLRNXJ
LRNXJJUXOOKDM
JUXOOKDMHEXAO
AOGTWSKNUCTOQ
NUCTOQKKCYRIE
QKKCYRIEIDUXV
UXVBDQKAFGXJS
SJFVSGRSCSMSG
GOHOZVNCDTSJN
DTSJNBSCNLOIL
SCNLOILSMORFQ
9 73
NOFBDVZHA
BDVZHANAJ
PSJKZGVXW
PSJKZGVXW
VXWSQFPYV
XWSQFPYVE
QFPYVEWZR
PYVEWZRNC
PYVEWZRNC
EWZRNCHJG
EWZRNCHJG
CHJGQOWZE
OTOKORQFR
FRMIIPNVJ
IPNVJJSXY
JJSXYKTZC
JSXYKTZCU
CUJVDUOWO
WOSSEPOYU
SEPOYUYPH
OYUYPHYVS
PHYVSWFMV
WJQWKDYBN
DYBNLWWPK
WPKEYHJWY
PKEYHJWYR
EYHJWYRGG
YHJWYRGGW
WTGINTJFP
FPTCVEPQE
PQEOBQYCX
QYCXUEVRX
RXYVRQTMC
XYVRQTMCO
QTMCOGCON
ONHXZOXWZ
ZJEIHMCEB
BWBBBCHCA
BBCHCAIQM
BBCHCAIQM
HCAIQMGSV
QMGSVNPRR
PRRKFPASI
SICXOFDEN
DENKJAYZH
AYZHSGGHK
AYZHSGGHK
GGHKHXWIC
XWICPJJCY
CPJJCYVOM
YVOMORURA
UDDYWCXMS
CXMSZCDOV
OVIBMNDND
VIBMNDNDQ
BMNDNDQJC
CFSNGACPK
SCMYBCLPR
CLPRNDSFT
PRNDSFTXC
PRNDSFTXC
DSFTXCZLT
TFWUTDCWM
TDCWMTICU
CUYTRQQXU
RQQXUNYFE
YFEGNRKSS
NRKSSVXYH
NRKSSVXYH
SVXYHXQXX
XJIMRVTTJ
JIMRVTTJP
ZOSTMMIQA
26 77
AFFKKMKKBGUVLPNSPUEYEZTTHI
UEYEZTTHITLNXEHNSXQQGVCVSH
TLNXEHNSXQQGVCVSHETAEBLXDX
BLXDXQFFURBNVGOJCMVVERVRGY
BLXDXQFFURBNVGOJCMVVERVRGY
FFURBNVGOJCMVVERVRGYWNLEXW
JCMVVERVRGYWNLEXWOYQTOKQCJ
GYWNLEXWOYQTOKQCJGXOLEPUTS
GXOLEPUTSQHXDWWODOHLSODUIX
OLEPUTSQHXDWWODOHLSODUIXMQ
QHXDWWODOHLSODUIXMQLYMBXAF
WODOHLSODUIXMQLYMBXAFLHMOV
ODUIXMQLYMBXAFLHMOVXZSGQUS
XMQLYMBXAFLHMOVXZSGQUSYWSB
XZSGQUSYWSBNOXAWNMZZFELSYG
YGTQUHUXTFFDECZUEFREUJYNTS
TQUHUXTFFDECZUEFREUJYNTSOD
HUXTFFDECZUEFREUJYNTSODOIS
SKWXZIHTABLOJSUWKFAGGGKMCL
WKFAGGGKMCLVQAAPHCCWHSTCVA
MCLVQAAPHCCWHSTCVAXZEXHXGC
XGCNEMCTCIWKQPBDQJCIFKEGBL
FKEGBLNDUSSWKMPNLAKWURCORM
BLNDUSSWKMPNLAKWURCORMVMNJ
MNJMTUYNDAEFKCJUVVDFCBQUMP
BQUMPTWOFIENTWUQMKGTPTOVLE
LEHOUSJXCUXAAZJYYPFXHSPEIG
CCWMHEVHNSMICBGMLBNZSGYHYD
MLBNZSGYHYDBJGMVXQIKFWJXBM
BNZSGYHYDBJGMVXQIKFWJXBMOQ
QDBRNNCTMZYAKFQQVTGJWHCQOR
QDBRNNCTMZYAKFQQVTGJWHCQOR
DBRNNCTMZYAKFQQVTGJWHCQORS
VTGJWHCQORSPNUOOFIPUAVBIFO
OOFIPUAVBIFOORHYLKJAIZBDXL
BIFOORHYLKJAIZBDXLPIMZSEXU
EXUPOXIUYRTFOVXORTDMRIFIVH
TFOVXORTDMRIFIVHGWCSGUFTSL
VXORTDMRIFIVHGWCSGUFTSLLNI
UFTSLLNIRQWRNVDOGYDYOKONVG
TSLLNIRQWRNVDOGYDYOKONVGAV
AVVUNPYGYFKHLGXQAJKTQYPUDS
QAJKTQYPUDSFLXMCWWPYGXUENN
ENNRPERPHLGXWHTRDUOYNSNHWO
DUOYNSNHWORMGJWZXRUUXVZMUR
SNHWORMGJWZXRUUXVZMURGEEPT
UXVZMURGEEPTXFLYHUMJHOEAGM
URGEEPTXFLYHUMJHOEAGMDYWTR
FLYHUMJHOEAGMDYWTRHNAHWMUK
WTRHNAHWMUKGNVHCBKXQESBDNF
HNAHWMUKGNVHCBKXQESBDNFZZQ
HCBKXQESBDNFZZQRJYNITMRBUP
UPRHQGVUTXHHNSHPIIBSWDKJVZ
UPRHQGVUTXHHNSHPIIBSWDKJVZ
HNSHPIIBSWDKJVZWXGEFTZBDCI
IIBSWDKJVZWXGEFTZBDCIYUQOH
IBSWDKJVZWXGEFTZBDCIYUQOHB
BDCIYUQOHBWDDMKRIDUDYPYXBT
DMKRIDUDYPYXBTCHHFWGQJKETV
DYPYXBTCHHFWGQJKETVDCEJVJD
DYPYXBTCHHFWGQJKETVDCEJVJD
YPYXBTCHHFWGQJKETVDCEJVJDZ
VDCEJVJDZQJROWIUWHIWZNOUYX
CEJVJDZQJROWIUWHIWZNOUYXRD
HIWZNOUYXRDNLLIEOFNJETOBHN
LIEOFNJETOBHNLJTYLZGTAZDSJ
HNLJTYLZGTAZDSJQYDQPSXQDAG
GUXFSJNAYUUTHXMYVBBRMJHFXY
ZZNMODHSMNAJJXCOJOKSSDRCFG
NMODHSMNAJJXCOJOKSSDRCFGKY
KSSDRCFGKYMVLEUGXSPHGHISZA
SDRCFGKYMVLEUGXSPHGHISZAKY
UGXSPHGHISZAKYPNJVNFZFSJSL
GHISZAKYPNJVNFZFSJSLVAWYQO
GHISZAKYPNJVNFZFSJSLVAWYQO
YPNJVNFZFSJSLVAWYQOVHECGWI
HECGWIDEWYTDOKGVWDVHREPTUO
29 36
KCSOKCAWGHIIOQJYBYXQITOHEMFCB
ITOHEMFCBSZGXXCHKNSBRQQKOUJEA
ABAMCHTXEXNMMHTGYHWGHYVUOJKEQ
KEQQIYPAYEOCPNGDVONIVKKEDPFCG
KKEDPFCGRFGEVGJTSOCVEVZWKTUPD
VGJTSOCVEVZWKTUPDIKAHZHZCRTHL
TUPDIKAHZHZCRTHLUXIORYATFATXU
AHZHZCRTHLUXIORYATFATXUPJWKXI
RTHLUXIORYATFATXUPJWKXIKCOJZH
COJZHNLHALHUMMKLBFXCDOWPDSFVO
OJZHNLHALHUMMKLBFXCDOWPDSFVOS
NLHALHUMMKLBFXCDOWPDSFVOSRYIJ
WTBMKOIWPMXEDJADOWYJQFZTZFJGX
BMKOIWPMXEDJADOWYJQFZTZFJGXVP
WPMXEDJADOWYJQFZTZFJGXVPVDLEZ
VDLEZYAUHLWSZYTQCWAZROXVRAYWM
XVRAYWMSECABXMEEBYIEDADKFIQDE
IEDADKFIQDEIFRBUPRWOBMGKYORTK
BUPRWOBMGKYORTKAVBINALOHLMOCV
KYORTKAVBINALOHLMOCVJAVOTVMOO
OTVMOOLVXGLPADHIEQDDGBDJCFLWY
PADHIEQDDGBDJCFLWYANXJUAAIPAJ
DDGBDJCFLWYANXJUAAIPAJFGIYLCX
DGBDJCFLWYANXJUAAIPAJFGIYLCXW
CFLWYANXJUAAIPAJFGIYLCXWMDDZX
FGIYLCXWMDDZXBVFFCTMJJUSPSBKF
SPSBKFHDBDOEGRGRVQWJIPSZMNSKT
SKTVHJMQBYRIGFXXREUZHIDGBGWGK
YRIGFXXREUZHIDGBGWGKOKYDJOEYP
FXXREUZHIDGBGWGKOKYDJOEYPGGCN
IDGBGWGKOKYDJOEYPGGCNLIOXWIMH
YPGGCNLIOXWIMHIYZAIBBTODBIBRR
MHIYZAIBBTODBIBRRLOXDPJKSOEGC
HIYZAIBBTODBIBRRLOXDPJKSOEGCV
TODBIBRRLOXDPJKSOEGCVJHIEYHTK
ODBIBRRLOXDPJKSOEGCVJHIEYHTKK
31 20
HWNIDIOHLCXYLBRGUHCLMFHGYTEAGDJ
HGYTEAGDJRZRNSADNQNXTVQYGGATIEF
XTVQYGGATIEFIFOLLEYYEWJYBADVOIL
VHDNGVXUKMAIWFSPKTWEXSWQMNAGPJQ
IWFSPKTWEXSWQMNAGPJQLRXLDQCSPPK
SPKTWEXSWQMNAGPJQLRXLDQCSPPKGME
MNAGPJQLRXLDQCSPPKGMEYUPWZVTSXQ
RXLDQCSPPKGMEYUPWZVTSXQPARBWVRE
RXLDQCSPPKGMEYUPWZVTSXQPARBWVRE
UPWZVTSXQPARBWVREVFDNDWIVTYEOLG
VREVFDNDWIVTYEOLGPQMSLUDZCQRQXP
IVTYEOLGPQMSLUDZCQRQXPPUNHPDWNQ
PPUNHPDWNQFVXKSKWKAJKGRKLRNCEBM
AJKGRKLRNCEBMNHDAMIEOQKGSRWGEFZ
GEFZROGCIOEADXKGHYLWUVTCCRLQDXD
OGCIOEADXKGHYLWUVTCCRLQDXDMTJHR
GCIOEADXKGHYLWUVTCCRLQDXDMTJHRH
XDMTJHRHSDEJHAQAIJRWVSZNJCBBYPO
JRWVSZNJCBBYPOKZHWZYYXLWKQQYFGI
KZHWZYYXLWKQQYFGIZTGSPQNRIBUXLY
9 8
TVXEMVSRC
EMVSRCIAR
EMVSRCIAR
RMMUNSEKT
MMUNSEKTT
NSEKTTMFW
TMFWSNTQQ
WSNTQQUAC
12 47
GEXLYPOUANUQ
QHAGIVLWFNZI
GIVLWFNZITTS
ZRMRVYFJTOHM
ZRMRVYFJTOHM
JTOHMTJQCXQP
PWVOVQRVKYMA
OVQRVKYMAOCQ
QGWFCDGLXRMK
QGWFCDGLXRMK
FXQZTYQZLPMI
XQZTYQZLPMIG
TYQZLPMIGNBA
IFQTHZPJKXMM
XMMNQCZGQVYK
PUDCVUIDLAPD
VUIDLAPDLIMO
VUIDLAPDLIMO
VUIDLAPDLIMO
LAPDLIMOHXPB
XPBAGIYTQSBR
NXYSDMFVPLJY
VPLJYTSPUXCE
EHBMEHJDPNEH
HTADBANMLGBU
ANMLGBUHARWC
NMLGBUHARWCX
ARWCXOFCWAPW
RWCXOFCWAPWX
APWXGLLVDVJJ
SDKCICFRMPJQ
SDKCICFRMPJQ
JQJXJQCRZWSV
JQJXJQCRZWSV
WSVXROWGBCGC
WSVXROWGBCGC
VXROWGBCGCUO
OUSAQRGIWBGN
RGIWBGNHXOMQ
GNHXOMQGEXIT
HXOMQGEXITJV
OMQGEXITJVNG
PKSGKZSFOQGL
LGVZCUGOHIIA
GVZCUGOHIIAX
AXANTPHGMUNR
HGMUNRXFFYMJ
7 20
GAUKVEH
UKVEHNR
RDGPANP
DGPANPF
NTKZQLJ
NTKZQLJ
YKCICKR
BTIYGKM
KGSWFWA
WAHPDJR
JROJLLQ
ZWWVJUJ
ZWWVJUJ
UJIYSCJ
IYSCJVM
VMZTRWL
MZTRWLZ
MZTRWLZ
RWLZANK
KCQUCZO
34 26
XEZNYIHYOXNPPGRRYXZMNNCDFOJZAYLHNP
NPPGRRYXZMNNCDFOJZAYLHNPLYJJJAOJPQ
LHNPLYJJJAOJPQRVQTMEDXZNMSYNKJUBRG
TMEDXZNMSYNKJUBRGQBXFMBYIDCNPESMAY
GQBXFMBYIDCNPESMAYYLOXRXHXQAQMVHZV
XQAQMVHZVHNQTHDELPTRNTUDHLDCGJHKSC
XQAQMVHZVHNQTHDELPTRNTUDHLDCGJHKSC
HZVHNQTHDELPTRNTUDHLDCGJHKSCSDZSBV
LPTRNTUDHLDCGJHKSCSDZSBVJQTFTAORXQ
QTFTAORXQPQOKINMVDJLHKVSFNKMJENDQO
KINMVDJLHKVSFNKMJENDQOYLCINDAEUBUE
ECMCZVLGGEQRKXUDZOUIISFSMIETLVTARN
GEQRKXUDZOUIISFSMIETLVTARNSNOXGVDW
XUDZOUIISFSMIETLVTARNSNOXGVDWRYZAR
UDZOUIISFSMIETLVTARNSNOXGVDWRYZARX
DZOUIISFSMIETLVTARNSNOXGVDWRYZARXA
RNSNOXGVDWRYZARXAQXBHRMDVJCPTMJQNN
ARXAQXBHRMDVJCPTMJQNNWIOVUDZDBQKNC
CLOOYXYXVLRNTDQLDHWPYUBDSJEBIHJSCG
LOOYXYXVLRNTDQLDHWPYUBDSJEBIHJSCGE
HJSCGEWFTWIFKLNWDFTOFGYPUOPLGAXZUV
FGYPUOPLGAXZUVQZHICHTQDYMNWWMFEUHE
QDYMNWWMFEUHEYXOCKQCHVQHPWBXOOIBEB
XOCKQCHVQHPWBXOOIBEBIBCKPWIEAHQJFU
QJFULUTRQETHWMKNAENGYTSJZQHRKWHOUP
QHRKWHOUPNQHDTXJIZVWQYBHKRJSIDMSXR
20 7
KPLVNIBEJIYOHMXNJHEZ
ZGLAALXPKSIEMXLUWHTC
ALXPKSIEMXLUWHTCIRPL
EMXLUWHTCIRPLXOYOTVL
LXOYOTVLFMEZPIPJFPUE
OYOTVLFMEZPIPJFPUEDE
EDEHLFJIMNCSRLJXJYBC
*/