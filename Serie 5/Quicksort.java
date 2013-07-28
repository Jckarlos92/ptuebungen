import java.util.Random;

/* Empirische Messsung:
 * ====================
 * Um eine unsortierte Menge von 150000 zufälligen
 * Elementen zu sortieren, benötigt der Algorithmus 36271805ns = 36,2718ms.
 * Die Laufzeit im schlimmsten Falle (also auf einer schon sortierten Menge)
 * ließ sich erst ermitteln, nachdem die Stack-Größe angehoben wurde. Sonst
 * kam es zum Stack-Overflow. Damit dauerte das Sortieren auf einer schon sortierten
 * Menge 8194970143ns = 8194,96ms = 8,195s 
 *
 Informationen zum System:
 Arch Linux 3.9.8-1-ARCH #1 SMP PREEMPT
 Thinkpad T420

 >> cat /proc/cpuinfo
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 42
model name	: Intel(R) Core(TM) i5-2520M CPU @ 2.50GHz
stepping	: 7
microcode	: 0x17
cpu MHz		: 1225.000
cache size	: 3072 KB
physical id	: 0
siblings	: 4
core id		: 0
cpu cores	: 2
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 13
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx rdtscp lm constant_tsc arch_perfmon pebs bts nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic popcnt tsc_deadline_timer aes xsave avx lahf_lm ida arat epb xsaveopt pln pts dtherm tpr_shadow vnmi flexpriority ept vpid
bogomips	: 4986.76
clflush size	: 64
cache_alignment	: 64
address sizes	: 36 bits physical, 48 bits virtual
power management:

processor	: 1
vendor_id	: GenuineIntel
cpu family	: 6
model		: 42
model name	: Intel(R) Core(TM) i5-2520M CPU @ 2.50GHz
stepping	: 7
microcode	: 0x17
cpu MHz		: 2425.000
cache size	: 3072 KB
physical id	: 0
siblings	: 4
core id		: 0
cpu cores	: 2
apicid		: 1
initial apicid	: 1
fpu		: yes
fpu_exception	: yes
cpuid level	: 13
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx rdtscp lm constant_tsc arch_perfmon pebs bts nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic popcnt tsc_deadline_timer aes xsave avx lahf_lm ida arat epb xsaveopt pln pts dtherm tpr_shadow vnmi flexpriority ept vpid
bogomips	: 4986.76
clflush size	: 64
cache_alignment	: 64
address sizes	: 36 bits physical, 48 bits virtual
power management:

processor	: 2
vendor_id	: GenuineIntel
cpu family	: 6
model		: 42
model name	: Intel(R) Core(TM) i5-2520M CPU @ 2.50GHz
stepping	: 7
microcode	: 0x17
cpu MHz		: 1275.000
cache size	: 3072 KB
physical id	: 0
siblings	: 4
core id		: 1
cpu cores	: 2
apicid		: 2
initial apicid	: 2
fpu		: yes
fpu_exception	: yes
cpuid level	: 13
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx rdtscp lm constant_tsc arch_perfmon pebs bts nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic popcnt tsc_deadline_timer aes xsave avx lahf_lm ida arat epb xsaveopt pln pts dtherm tpr_shadow vnmi flexpriority ept vpid
bogomips	: 4986.76
clflush size	: 64
cache_alignment	: 64
address sizes	: 36 bits physical, 48 bits virtual
power management:

processor	: 3
vendor_id	: GenuineIntel
cpu family	: 6
model		: 42
model name	: Intel(R) Core(TM) i5-2520M CPU @ 2.50GHz
stepping	: 7
microcode	: 0x17
cpu MHz		: 1200.000
cache size	: 3072 KB
physical id	: 0
siblings	: 4
core id		: 1
cpu cores	: 2
apicid		: 3
initial apicid	: 3
fpu		: yes
fpu_exception	: yes
cpuid level	: 13
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx rdtscp lm constant_tsc arch_perfmon pebs bts nopl xtopology nonstop_tsc aperfmperf eagerfpu pni pclmulqdq dtes64 monitor ds_cpl vmx smx est tm2 ssse3 cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic popcnt tsc_deadline_timer aes xsave avx lahf_lm ida arat epb xsaveopt pln pts dtherm tpr_shadow vnmi flexpriority ept vpid
bogomips	: 4986.76
clflush size	: 64
cache_alignment	: 64
address sizes	: 36 bits physical, 48 bits virtual
power management:

 >> cat /proc/meminfo
MemTotal:        8065368 kB
MemFree:         6913684 kB
Buffers:           34132 kB
Cached:           439324 kB
SwapCached:            0 kB
Active:           597096 kB
Inactive:         404760 kB
Active(anon):     529756 kB
Inactive(anon):   117572 kB
Active(file):      67340 kB
Inactive(file):   287188 kB
Unevictable:           0 kB
Mlocked:               0 kB
SwapTotal:       8000364 kB
SwapFree:        8000364 kB
Dirty:               188 kB
Writeback:             0 kB
AnonPages:        528488 kB
Mapped:            96852 kB
Shmem:            118868 kB
Slab:              38072 kB
SReclaimable:      22268 kB
SUnreclaim:        15804 kB
KernelStack:        1616 kB
PageTables:         8680 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:    12033048 kB
Committed_AS:    1508684 kB
VmallocTotal:   34359738367 kB
VmallocUsed:      383700 kB
VmallocChunk:   34359340028 kB
HardwareCorrupted:     0 kB
AnonHugePages:    126976 kB
HugePages_Total:       0
HugePages_Free:        0
HugePages_Rsvd:        0
HugePages_Surp:        0
Hugepagesize:       2048 kB
DirectMap4k:       11904 kB
DirectMap2M:     8261632 kB
 */

class Quicksort {	
    public static void main(String[] args) {
        System.out.println("Empirischer Vergleich von Quicksort-Laufzeiten");
        System.out.println("    auf sortierten und unsortierten Mengen");
        System.out.println("==============================================");

        int n      = 150000;
        int iArr[] = new int[n];
        Random randomGen = new Random();

        /* erzeuge Normalfall */
        for (int i = 0; i < n; i++)
            iArr[i] = randomGen.nextInt();

        long averageCasebegin = java.lang.System.nanoTime();
        quicksort(iArr, 0, n-1);
        long averageCasetime = java.lang.System.nanoTime() - averageCasebegin;
        
        /* erzeuge worst-case Szenario */
        for (int i = 0; i < n; ++i)
            iArr [i] = i;

        long worstCasebegin = java.lang.System.nanoTime();
        quicksort(iArr, 0, n-1);
        long worstCasetime = java.lang.System.nanoTime() - worstCasebegin;


        System.out.println("Laufzeit auf unsortierter Menge: " + averageCasetime + "ns" );
        System.out.println("Laufzeit auf   sortierter Menge: " + worstCasetime + "ns" );
    }

    static void quicksort(int[] array, int left, int right) { 
        if (right <= left)
            return;

        int pivotIndex = partition(array, left, right);

        quicksort(array, left, pivotIndex-1);
        quicksort(array, pivotIndex+1, right);
    }

    static int partition(int a[], int left, int right) {
        int i = left-1;
        int j = right;
        int tmp;

        while(true) { 
            for (++i; a[i] < a[right]; ++i);

            for (--j; a[right] < a[j]; --j) {
                if (j == left)
                    break;
            }

            if (i >= j) break;

            tmp = a[i];
            a[i]    = a[j];
            a[j]    = tmp;
        }
            
       tmp      = a[i];
       a[i]     = a[right];
       a[right] = tmp;
       
       return i;
    }
}
